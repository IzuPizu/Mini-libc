// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length) {
    int retc;
    retc = syscall(__NR_truncate, path, length);

    if (retc < 0) {
        errno = -retc;
        return -1;
    }

    return 0;
}
