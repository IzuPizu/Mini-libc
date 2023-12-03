#include <time.h>
#include <unistd.h>

unsigned sleep(unsigned seconds) {
    int retc;
    struct timespec req = {req.tv_sec = seconds, req.tv_nsec = 0};
    struct timespec rem;

    retc = nanosleep(&req, &rem);
    if (retc == -1) {
        return req.tv_sec;
    }
    return 0;
}
