#include <errno.h>
#include <internal/syscall.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long retc;

    retc = syscall(__NR_nanosleep, req, rem);
    if (retc < 0) {
        errno = -retc;
        return -1;
    }
    return 0;
}
