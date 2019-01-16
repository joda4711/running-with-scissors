#pragma once

#include <sys/capability.h>

struct rws_cap {
    cap_value_t value;
    const char *name;
    const char *doc;
};

extern const struct rws_cap rws_caps[];
extern unsigned int rws_ncaps;
