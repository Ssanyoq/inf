#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"


char *readline() {
    int limit = 255;
    char *str = safe_malloc(limit);
    int out = scanf("%255[^\n]", str);
    if (out == -1) {
        return NULL;
    return str;
}

