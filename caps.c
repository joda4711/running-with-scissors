/* this file is generated from /usr/include/linux/capability.h */
#include "rws.h"

const struct rws_cap rws_caps[] = {
    {
        CAP_CHOWN,
        "CAP_CHOWN",
        "In a system with the [_POSIX_CHOWN_RESTRICTED] option defined, this\n"
        "overrides the restriction of changing file ownership and group\n"
        "ownership.\n"
    },
    {
        CAP_DAC_OVERRIDE,
        "CAP_DAC_OVERRIDE",
        "Override all DAC access, including ACL execute access if\n"
        "[_POSIX_ACL] is defined. Excluding DAC access covered by\n"
        "CAP_LINUX_IMMUTABLE.\n"
    },
    {
        CAP_DAC_READ_SEARCH,
        "CAP_DAC_READ_SEARCH",
        "Overrides all DAC restrictions regarding read and search on files\n"
        "and directories, including ACL restrictions if [_POSIX_ACL] is\n"
        "defined. Excluding DAC access covered by CAP_LINUX_IMMUTABLE.\n"
    },
    {
        CAP_FOWNER,
        "CAP_FOWNER",
        "Overrides all restrictions about allowed operations on files, where\n"
        "file owner ID must be equal to the user ID, except where CAP_FSETID\n"
        "is applicable. It doesn't override MAC and DAC restrictions.\n"
    },
    {
        CAP_FSETID,
        "CAP_FSETID",
        "Overrides the following restrictions that the effective user ID\n"
        "shall match the file owner ID when setting the S_ISUID and S_ISGID\n"
        "bits on that file; that the effective group ID (or one of the\n"
        "supplementary group IDs) shall match the file owner ID when setting\n"
        "the S_ISGID bit on that file; that the S_ISUID and S_ISGID bits are\n"
        "cleared on successful return from chown(2) (not implemented).\n"
    },
    {
        CAP_KILL,
        "CAP_KILL",
        "Overrides the restriction that the real or effective user ID of a\n"
        "process sending a signal must match the real or effective user ID\n"
        "of the process receiving the signal.\n"
    },
    {
        CAP_SETGID,
        "CAP_SETGID",
        "Allows setgid(2) manipulation\n"
        "Allows setgroups(2)\n"
        "Allows forged gids on socket credentials passing.\n"
    },
    {
        CAP_SETUID,
        "CAP_SETUID",
        "Allows set*uid(2) manipulation (including fsuid).\n"
        "Allows forged pids on socket credentials passing.\n"
    },
    {
        CAP_SETPCAP,
        "CAP_SETPCAP",
        "Without VFS support for capabilities:\n"
        "  Transfer any capability in your permitted set to any pid,\n"
        "  remove any capability in your permitted set from any pid\n"
        "With VFS support for capabilities (neither of above, but)\n"
        "  Add any capability from current's capability bounding set\n"
        "      to the current process' inheritable set\n"
        "  Allow taking bits out of capability bounding set\n"
        "  Allow modification of the securebits for a process\n"
        "\n"
    },
    {
        CAP_LINUX_IMMUTABLE,
        "CAP_LINUX_IMMUTABLE",
        "Allow modification of S_IMMUTABLE and S_APPEND file attributes\n"
    },
    {
        CAP_NET_BIND_SERVICE,
        "CAP_NET_BIND_SERVICE",
        "Allows binding to TCP/UDP sockets below 1024\n"
        "Allows binding to ATM VCIs below 32\n"
    },
    {
        CAP_NET_BROADCAST,
        "CAP_NET_BROADCAST",
        "Allow broadcasting, listen to multicast\n"
    },
    {
        CAP_NET_ADMIN,
        "CAP_NET_ADMIN",
        "Allow interface configuration\n"
        "Allow administration of IP firewall, masquerading and accounting\n"
        "Allow setting debug option on sockets\n"
        "Allow modification of routing tables\n"
        "Allow setting arbitrary process / process group ownership on\n"
        "sockets\n"
        "Allow binding to any address for transparent proxying (also via NET_RAW)\n"
        "Allow setting TOS (type of service)\n"
        "Allow setting promiscuous mode\n"
        "Allow clearing driver statistics\n"
        "Allow multicasting\n"
        "Allow read/write of device-specific registers\n"
        "Allow activation of ATM control sockets\n"
    },
    {
        CAP_NET_RAW,
        "CAP_NET_RAW",
        "Allow use of RAW sockets\n"
        "Allow use of PACKET sockets\n"
        "Allow binding to any address for transparent proxying (also via NET_ADMIN)\n"
    },
    {
        CAP_IPC_LOCK,
        "CAP_IPC_LOCK",
        "Allow locking of shared memory segments\n"
        "Allow mlock and mlockall (which doesn't really have anything to do\n"
        "with IPC)\n"
    },
    {
        CAP_IPC_OWNER,
        "CAP_IPC_OWNER",
        "Override IPC ownership checks\n"
    },
    {
        CAP_SYS_MODULE,
        "CAP_SYS_MODULE",
        "Insert and remove kernel modules - modify kernel without limit\n"
    },
    {
        CAP_SYS_RAWIO,
        "CAP_SYS_RAWIO",
        "Allow ioperm/iopl access\n"
        "Allow sending USB messages to any device via /dev/bus/usb\n"
    },
    {
        CAP_SYS_CHROOT,
        "CAP_SYS_CHROOT",
        "Allow use of chroot()\n"
    },
    {
        CAP_SYS_PTRACE,
        "CAP_SYS_PTRACE",
        "Allow ptrace() of any process\n"
    },
    {
        CAP_SYS_PACCT,
        "CAP_SYS_PACCT",
        "Allow configuration of process accounting\n"
    },
    {
        CAP_SYS_ADMIN,
        "CAP_SYS_ADMIN",
        "Allow configuration of the secure attention key\n"
        "Allow administration of the random device\n"
        "Allow examination and configuration of disk quotas\n"
        "Allow setting the domainname\n"
        "Allow setting the hostname\n"
        "Allow mount() and umount(), setting up new smb connection\n"
        "Allow some autofs root ioctls\n"
        "Allow nfsservctl\n"
        "Allow VM86_REQUEST_IRQ\n"
        "Allow to read/write pci config on alpha\n"
        "Allow irix_prctl on mips (setstacksize)\n"
        "Allow flushing all cache on m68k (sys_cacheflush)\n"
        "Allow removing semaphores\n"
        "Used instead of CAP_CHOWN to \"chown\" IPC message queues, semaphores\n"
        "and shared memory\n"
        "Allow locking/unlocking of shared memory segment\n"
        "Allow turning swap on/off\n"
        "Allow forged pids on socket credentials passing\n"
        "Allow setting readahead and flushing buffers on block devices\n"
        "Allow setting geometry in floppy driver\n"
        "Allow turning DMA on/off in xd driver\n"
        "Allow administration of md devices (mostly the above, but some\n"
        "extra ioctls)\n"
        "Allow tuning the ide driver\n"
        "Allow access to the nvram device\n"
        "Allow administration of apm_bios, serial and bttv (TV) device\n"
        "Allow manufacturer commands in isdn CAPI support driver\n"
        "Allow reading non-standardized portions of pci configuration space\n"
        "Allow DDI debug ioctl on sbpcd driver\n"
        "Allow setting up serial ports\n"
        "Allow sending raw qic-117 commands\n"
        "Allow enabling/disabling tagged queuing on SCSI controllers and sending\n"
        "arbitrary SCSI commands\n"
        "Allow setting encryption key on loopback filesystem\n"
        "Allow setting zone reclaim policy\n"
        "Allow everything under CAP_BPF and CAP_PERFMON for backward compatibility\n"
    },
    {
        CAP_SYS_BOOT,
        "CAP_SYS_BOOT",
        "Allow use of reboot()\n"
    },
    {
        CAP_SYS_NICE,
        "CAP_SYS_NICE",
        "Allow raising priority and setting priority on other (different\n"
        "UID) processes\n"
        "Allow use of FIFO and round-robin (realtime) scheduling on own\n"
        "processes and setting the scheduling algorithm used by another\n"
        "process.\n"
        "Allow setting cpu affinity on other processes\n"
        "Allow setting realtime ioprio class\n"
        "Allow setting ioprio class on other processes\n"
    },
    {
        CAP_SYS_RESOURCE,
        "CAP_SYS_RESOURCE",
        "Override resource limits. Set resource limits.\n"
        "Override quota limits.\n"
        "Override reserved space on ext2 filesystem\n"
        "Modify data journaling mode on ext3 filesystem (uses journaling\n"
        "resources)\n"
        "NOTE: ext2 honors fsuid when checking for resource overrides, so\n"
        "you can override using fsuid too\n"
        "Override size restrictions on IPC message queues\n"
        "Allow more than 64hz interrupts from the real-time clock\n"
        "Override max number of consoles on console allocation\n"
        "Override max number of keymaps\n"
        "Control memory reclaim behavior\n"
    },
    {
        CAP_SYS_TIME,
        "CAP_SYS_TIME",
        "Allow manipulation of system clock\n"
        "Allow irix_stime on mips\n"
        "Allow setting the real-time clock\n"
    },
    {
        CAP_SYS_TTY_CONFIG,
        "CAP_SYS_TTY_CONFIG",
        "Allow configuration of tty devices\n"
        "Allow vhangup() of tty\n"
    },
    {
        CAP_MKNOD,
        "CAP_MKNOD",
        "Allow the privileged aspects of mknod()\n"
    },
    {
        CAP_LEASE,
        "CAP_LEASE",
        "Allow taking of leases on files\n"
    },
    {
        CAP_AUDIT_WRITE,
        "CAP_AUDIT_WRITE",
        "Allow writing the audit log via unicast netlink socket\n"
    },
    {
        CAP_AUDIT_CONTROL,
        "CAP_AUDIT_CONTROL",
        "Allow configuration of audit via unicast netlink socket\n"
    },
    {
        CAP_SETFCAP,
        "CAP_SETFCAP",
        "Set or remove capabilities on files.\n"
        "Map uid=0 into a child user namespace.\n"
    },
    {
        CAP_MAC_OVERRIDE,
        "CAP_MAC_OVERRIDE",
        "Override MAC access.\n"
        "The base kernel enforces no MAC policy.\n"
        "An LSM may enforce a MAC policy, and if it does and it chooses\n"
        "to implement capability based overrides of that policy, this is\n"
        "the capability it should use to do so.\n"
    },
    {
        CAP_MAC_ADMIN,
        "CAP_MAC_ADMIN",
        "Allow MAC configuration or state changes.\n"
        "The base kernel requires no MAC configuration.\n"
        "An LSM may enforce a MAC policy, and if it does and it chooses\n"
        "to implement capability based checks on modifications to that\n"
        "policy or the data required to maintain it, this is the\n"
        "capability it should use to do so.\n"
    },
    {
        CAP_SYSLOG,
        "CAP_SYSLOG",
        "Allow configuring the kernel's syslog (printk behaviour)\n"
    },
    {
        CAP_WAKE_ALARM,
        "CAP_WAKE_ALARM",
        "Allow triggering something that will wake the system\n"
    },
    {
        CAP_BLOCK_SUSPEND,
        "CAP_BLOCK_SUSPEND",
        "Allow preventing system suspends\n"
    },
    {
        CAP_AUDIT_READ,
        "CAP_AUDIT_READ",
        "Allow reading the audit log via multicast netlink socket\n"
    },
    {
        CAP_PERFMON,
        "CAP_PERFMON",
        "Allow system performance and observability privileged operations\n"
        "using perf_events, i915_perf and other kernel subsystems\n"
        "\n"
    },
    {
        CAP_BPF,
        "CAP_BPF",
        "CAP_BPF allows the following BPF operations:\n"
        "- Creating all types of BPF maps\n"
        "- Advanced verifier features\n"
        "  - Indirect variable access\n"
        "  - Bounded loops\n"
        "  - BPF to BPF function calls\n"
        "  - Scalar precision tracking\n"
        "  - Larger complexity limits\n"
        "  - Dead code elimination\n"
        "  - And potentially other features\n"
        "- Loading BPF Type Format (BTF) data\n"
        "- Retrieve xlated and JITed code of BPF programs\n"
        "- Use bpf_spin_lock() helper\n"
        "\n"
        "CAP_PERFMON relaxes the verifier checks further:\n"
        "- BPF progs can use of pointer-to-integer conversions\n"
        "- speculation attack hardening measures are bypassed\n"
        "- bpf_probe_read to read arbitrary kernel memory is allowed\n"
        "- bpf_trace_printk to print kernel memory is allowed\n"
        "\n"
        "CAP_SYS_ADMIN is required to use bpf_probe_write_user.\n"
        "\n"
        "CAP_SYS_ADMIN is required to iterate system wide loaded\n"
        "programs, maps, links, BTFs and convert their IDs to file descriptors.\n"
        "\n"
        "CAP_PERFMON and CAP_BPF are required to load tracing programs.\n"
        "CAP_NET_ADMIN and CAP_BPF are required to load networking programs.\n"
        "\n"
    },
    {
        CAP_CHECKPOINT_RESTORE,
        "CAP_CHECKPOINT_RESTORE",
        "Allow checkpoint/restore related operations\n"
        "Allow PID selection during clone3()\n"
        "Allow writing to ns_last_pid\n"
    },
};

unsigned int rws_ncaps = 41;
