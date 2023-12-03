// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset) {
    long retc;

    if (length == 0) {
        errno = EINVAL;
        return MAP_FAILED;
    }
    if (fd != -1 || offset != 0) {
        errno = EBADF;
        return MAP_FAILED;
    }

    if (!(flags & (MAP_SHARED | MAP_PRIVATE))) {
        errno = EINVAL;
        return MAP_FAILED;
    }

    retc = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    if (retc < 0) {
        errno = -retc;
        return MAP_FAILED;
    }

    return (void *)retc;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    long retc;
    if (new_size == 0) {
        errno = EINVAL;
        return MAP_FAILED;
    }

    retc = syscall(__NR_mremap, old_address, old_size, new_size, flags);
    if (retc < 0) {
        errno = -retc;
        return MAP_FAILED;
    }
    return (void *)retc;
}

int munmap(void *addr, size_t length) {
    int retc;
    retc = syscall(__NR_munmap, addr, length);
    if (retc < 0) {
        errno = -retc;
        return -1;
    }

    return 0;
}
