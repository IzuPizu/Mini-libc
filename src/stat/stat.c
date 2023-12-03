// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *restrict buf) {
    int retc;
    retc = syscall(__NR_stat, path, buf);
    if (retc < 0) {
        errno = -retc;
        return -1;
    }
    return retc;
}
