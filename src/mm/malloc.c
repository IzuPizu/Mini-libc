// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
    void *mem_ptr;

    if (size == 0) {
        return NULL;
    }

    mem_ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
                   -1, 0);

    if (mem_ptr == MAP_FAILED) {
        return NULL;
    }

    memset(mem_ptr, 0, size);
    mem_list_add(mem_ptr, size);
    return mem_ptr;
}

void *calloc(size_t nmemb, size_t size) {
    void *mem_ptr;
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t final_size = size * nmemb;
    mem_ptr = mmap(0, final_size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem_ptr == MAP_FAILED) {
        return NULL;
    }

    if (mem_ptr != NULL) {
        memset(mem_ptr, 0, final_size);
    }

    return mem_ptr;
}

void free(void *ptr) {
    struct mem_list *mem_block;
    mem_block = mem_list_find(ptr);

    if (mem_block == NULL) {
        return;
    }
    if (ptr == NULL) {
        return;
    }

    munmap(ptr, mem_block->len);
    mem_list_del(ptr);

    return;
}

void *realloc(void *ptr, size_t size) {
    void *mem_ptr;
    struct mem_list *mem_block;
    mem_block = mem_list_find(ptr);

    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    mem_ptr = malloc(size);

    if (mem_ptr == NULL) {
        return NULL;
    }

    memcpy(mem_ptr, ptr, mem_block->len);
    free(ptr);

    return mem_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;

    if (nmemb == 0 || size == 0) {
        free(ptr);
        return NULL;
    }

    return realloc(ptr, total_size);
}
