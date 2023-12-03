// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd) {
    int retc;
    if (fd < 0) {
        errno = EBADF;
        return -1;
    }

    retc = syscall(__NR_close, fd);
    if (retc < 0) {
        errno = -retc;
        return -1;
    }
    return 0;
}

