// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence) {
    off_t retc;
    retc = syscall(__NR_lseek, fd, offset, whence);

    if (retc < 0) {
        errno = -retc;
        return (off_t)-1;
    }

    return retc;
}
