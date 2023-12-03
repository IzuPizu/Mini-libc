#include <errno.h>
#include <internal/syscall.h>
#include <stdio.h>
#include <unistd.h>

int puts(const char *str) {
    int retc;

    if (str == NULL) {
        return -1;
    }

    while (*str != '\0') {
        retc = write(1, str, 1);
        if (retc == -1) {
            return -1;
        }
        str++;
    }

    retc = write(1, "\n", 1);
    if (retc == -1) {
        return -1;
    }
    return 0;
}
