#include <stdlib.h>
#include <stdio.h>

void *safe_malloc(int len) {
    void *ptr = malloc(len);
    if (!ptr) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return ptr;
}

void *safe_realloc(void *ptr, int len) {
    ptr = realloc(ptr, len);
    if (!ptr) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return ptr;
}