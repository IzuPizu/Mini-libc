// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st) {
    int retc;
    retc = syscall(__NR_fstat, fd, st);
    if (retc < 0) {
        errno = -retc;
        return -1;
    }
    return retc;
}
