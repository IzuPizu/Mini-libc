#ifndef _TIME_H
#define _TIME_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
#include <time.h>

typedef int time_t;
typedef int clock_t;

struct timespec {
    time_t tv_sec;
    long int tv_nsec;
};

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

int nanosleep(const struct timespec *, struct timespec *);

#ifdef __cplusplus
}
#endif

#endif
