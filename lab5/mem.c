#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

void *safe_malloc(int len) {
    char *str = (char*)malloc(len);
    if (!str) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return str;
}

void *safe_realloc(char *str, int len) {
    str = (char *)realloc(str, len);
    if (!str) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    return str;
}
  
