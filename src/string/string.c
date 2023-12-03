// SPDX-License-Identifier: BSD-3-Clause
/* [SOURCE] https://en.wikibooks.org/wiki/C_Programming/String_manipulation */
#include <string.h>

char *strcpy(char *destination, const char *source) {
    unsigned i;
    for (i = 0; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    char *dst = destination;
    const char *src = source;
    while (len > 0) {
        len--;
        if ((*dst++ = *src++) == '\0') break;
    }
    while (len > 0) {
        *dst++ = '\0';
        --len;
    }
    return destination;
}

char *strcat(char *destination, const char *source) {
    char *s = destination;
    while (*s != '\0') {
        s++;
    }
    strcpy(s, source);
    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    char *s = destination;
    while (*s != '\0') {
        s++;
    }
    while (len != 0 && (*s = *source++) != '\0') {
        len--;
        s++;
    }
    if (*s != '\0') {
        *s = '\0';
    }
    return destination;
}

int strcmp(const char *str1, const char *str2) {
    for (; *str1 == *str2; str1++, str2++)
        if (*str1 == '\0') return 0;

    if (*str1 < *str2) {
        return -1;
    } else if (*str1 > *str2) {
        return 1;
    }
    return -1;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    if (len == 0) {
        return 0;
    }
    while (len > 0) {
        if (*str1 != *str2) {
            return (int)(*str1 - *str2);
        }
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
        len--;
    }
    return 0;
}

size_t strlen(const char *str) {
    const char *p = str;
    while (*p != '\0') {
        p++;
    }
    return (size_t)(p - str);
}

char *strchr(const char *str, int c) {
    char ch = c;
    while (*str != '\0' && *str != ch) {
        str++;
    }
    if (*str == ch) {
        return (char *)str;
    }
    return NULL;
}

char *strrchr(const char *str, int c) {
    const char *last = NULL;
    if (c == '\0') {
        return strchr(str, c);
    }
    while (*str != '\0') {
        if (*str == (char)c) {
            last = (char *)str;
        }
        str++;
    }

    return (char *)last;
}

char *strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h == *n && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)(haystack + strlen(haystack));
    }

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (haystack_len < needle_len) {
        return NULL;
    }

    for (int i = haystack_len - needle_len; i >= 0; i--) {
        if (strncmp(haystack + i, needle, needle_len) == 0) {
            return (char *)(haystack + i);
        }
    }
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
    char *dst = destination;
    const char *src = source;
    while (num-- != 0) {
        *dst++ = *src++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    char *p1 = destination;
    const char *p2 = source;

    if (p2 < p1 && p1 < p2 + num) {
        p2 += num;
        p1 += num;
        while (num-- != 0) {
            *--p1 = *--p2;
        }
    } else {
        while (num-- != 0) {
            *p1++ = *p2++;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    const unsigned char *us1 = (const unsigned char *)ptr1;
    const unsigned char *us2 = (const unsigned char *)ptr2;
    while (num-- != 0) {
        if (*us1 != *us2) {
            if (*us1 < *us2) {
                return -1;
            } else if (*us1 > *us2) {
                return 1;
            }
        }
        us1++;
        us2++;
    }
    return 0;
}

void *memset(void *source, int value, size_t num) {
    unsigned char *us = source;
    unsigned char uc = value;
    while (num-- != 0) *us++ = uc;
    return source;
}
