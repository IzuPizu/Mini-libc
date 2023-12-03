// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length) {
    int retc;
    retc = syscall(__NR_ftruncate, fd, length);

    if (retc < 0) {
        errno = -retc;
        return -1;
    }
    return 0;
}
