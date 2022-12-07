#include <stdlib.h>
#include <stdio.h>
#include "mem.h"

char *safe_malloc(int len) {
    char *str = (char*)malloc(len * sizeof(char));
    if (!str) {
        printf("Error occured while allocating memory\n");
        return NULL;
    }
    return str;
}