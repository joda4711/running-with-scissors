#define _GNU_SOURCE
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <pwd.h>
#include <grp.h>

#include "rws.h"

cap_value_t *caps;
int ncaps;

void set_cap(cap_flag_t flag)
{
    cap_t cap;

    cap = cap_get_proc();
    if(cap == NULL)
        err(1, "cap_get_proc");

    if(cap_set_flag(cap, flag, ncaps, caps, CAP_SET) < 0)
        err(1, "cap_set_flags");

    if(cap_set_proc(cap) < 0)
        err(1, "cap_set_proc");

    if(cap_free(cap) < 0)
        err(1, "cap_free");
}

/* -u user -c cap command args... */

const struct rws_cap *find_cap_by_name(const char *name)
{
    unsigned int i;
    const struct rws_cap *best = NULL;
    int multi = 0;

    for(i = 0; i < rws_ncaps; i++)
        if(strcmp(rws_caps[i].name, name) == 0)
            return &rws_caps[i];
    for(i = 0; i < rws_ncaps; i++) {
        if(strcasestr(rws_caps[i].name, name) != NULL) {
            if(best == NULL) {
                best = &rws_caps[i];
                continue;
            }
            if(multi == 0) {
                multi = 1;
                fprintf(stderr, "Multiple capabilities match \"%s\"\n", name);
            }
            fprintf(stderr, "    %s\n", best->name);
            best = &rws_caps[i];
        }
    }
    if(best == NULL) {
        fprintf(stderr, "Unknown capability \"%s\"\n", name);
        return NULL;
    }
    if(multi == 0)
        return best;
    fprintf(stderr, "    %s\n", best->name);
    return NULL;
}


const struct rws_cap *find_cap_by_id(cap_value_t cap)
{
    unsigned int i;

    for(i = 0; i < rws_ncaps; i++)
        if(rws_caps[i].value == cap)
            return &rws_caps[i];
    return NULL;
}

void print_cap(const struct rws_cap *c)
{
        fprintf(stderr, "%s\n", c->name);
        fprintf(stderr, "%s\n", c->doc);
}

void
list_caps(void)
{
    unsigned int i;

    for(i = 0; i < rws_ncaps; i++) {
        print_cap(&rws_caps[i]);
        fprintf(stderr, "\n");
    }
}

void list_cap_by_descr(const char *substr)
{
    unsigned int i;
    int first = 1;

    for(i = 0; i < rws_ncaps; i++) {
        if(strcasestr(rws_caps[i].name, substr) != NULL
           || strcasestr(rws_caps[i].doc, substr) != NULL) {
            if(!first)
                fprintf(stderr, "\n");
            print_cap(&rws_caps[i]);
            first = 0;
        }
    }
}

#define NOUID ((uid_t)-1)
#define NOGID ((gid_t)-1)

uid_t uid = NOUID;
gid_t gid = NOGID;
gid_t *groups;
int ngroups;

/* obtain supplementary group list for username */
void rws_getsupp(char *username, gid_t gid)
{
    if(getgrouplist(username, gid, groups, &ngroups) >= 0)
        return;

    groups = realloc(groups, ngroups*sizeof(*groups));
    if(groups == NULL)
        err(EXIT_FAILURE, "Out of memory");

    if(getgrouplist(username, gid, groups, &ngroups) >= 0)
        return;

    errx(EXIT_FAILURE, "Failed to get group list for %s", username);
}

//SUDO_UID, SUDO_GID

//setgroups()

void rws_getgid(char *group)
{
    gid_t g;
    char *end;
    struct group *grp;

    g = strtoul(group, &end, 10);
    if(*end == '\0') {
        gid = g;
        return;
    }
    grp = getgrnam(group);
    if(grp != NULL) {
        gid = grp->gr_gid;
        return;
    }
    errx(EXIT_FAILURE, "unable to parse group \"%s\"", group);
}

void rws_getuid(char *user)
{
    uid_t u;
    char *end;
    struct passwd *pw;

    end = strchr(user, ':');
    if(end != NULL) {
        *end = '\0';
        rws_getgid(end+1);
    }

    u = strtoul(user, &end, 10);
    if(*end == '\0') {
        uid = u;
        return;
    }
    pw = getpwnam(user);
    if(pw != NULL) {
        uid = pw->pw_uid;
        if(gid == NOGID)
            gid = pw->pw_gid;
        rws_getsupp(pw->pw_name, gid);
        return;
    }
    errx(EXIT_FAILURE, "unable to parse user \"%s\"", user);
}


int main(int argc, char **argv)
{
    int opt;
    struct group *group;
    const struct rws_cap *c;

    while((opt = getopt(argc, argv, "lu:c:s:")) != -1) {
        switch(opt) {
        case 'l':
            list_caps();
            exit(0);
        case 's':
            list_cap_by_descr(optarg);
            exit(0);
        case 'u':
            rws_getuid(optarg);
            break;
        case 'g':
            rws_getgid(optarg);
            break;
        case 'c':
            c = find_cap_by_name(optarg);
            if(c == NULL)
                exit(EXIT_FAILURE);
            caps = realloc(caps, (ncaps + 1) * sizeof(*caps));
            if(caps == NULL)
                errx(EXIT_FAILURE, "Out of memory");
            caps[ncaps++] = c->value;
            break;
        default:
            fprintf(stderr, "Usage: rws -u user -c cap command args...\n");
            exit(EXIT_FAILURE);
        }
    }
    if(optind >= argc) {
        fprintf(stderr, "Usage: rws [-u user] [-g group] [-c cap]... command args...\n");
        exit(EXIT_FAILURE);
    }

    if(uid == NOUID && getuid() != geteuid()) {
        uid = getuid();
        gid = getgid();
    }

    if(uid == NOUID && getenv("SUDO_USER") != NULL)
        rws_getuid(getenv("SUDO_USER"));

    if(uid == NOUID)
        errx(EXIT_FAILURE, "unable to determine uid, specify with -u");
    if(gid == NOGID)
        errx(EXIT_FAILURE, "unable to determine gid, specify with -g");

    /* set inheritable */
    set_cap(CAP_INHERITABLE);

    /* make sure setuid doesn't drop caps */
    if(prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0) < 0)
        err(1, "PR_SET_KEEPCAPS");

    if(setgroups(ngroups, groups) < 0)
        warn("setgroups");

    if(setgid(gid) < 0)
        err(1, "setgid");

    if(setuid(uid) < 0)
        err(1, "setuid");

    /* effective bit was lost */
    set_cap(CAP_EFFECTIVE);

    /* include in ambient */
    for(__auto_type i = 0; i < ncaps; i++)
        if(prctl(PR_CAP_AMBIENT, PR_CAP_AMBIENT_RAISE, caps[i], 0, 0) < 0)
            err(1, "PR_CAP_AMBIENT");

    execvp(argv[optind], &argv[optind]);
    return -1;
}
