#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"

char *readline() {
    const int limit = 254;
    char *str = safe_malloc(limit);
    char c;
    for (int i = 0; i < limit; i++) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        } 
        printf("%c", c);
        str[i] = c;
    }
    return str;
}