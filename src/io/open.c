// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...) {
    int mode = 0;
    int retc;

    if (flags & O_CREAT) {
        va_list arg;
        va_start(arg, flags);
        mode = va_arg(arg, int);
        va_end(arg);
    }

    retc = syscall(__NR_open, filename, flags, mode);

    if (retc < 0) {
        errno = -retc;
        return -1;
    }

    return retc;
}
