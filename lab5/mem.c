#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

void *safe_malloc(int len) {
    void *str = malloc(len);
    if (!str) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return str;
}

void *safe_realloc(void *str, int len) {
    str = realloc(str, len);
    if (!str) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return str;
}
  
