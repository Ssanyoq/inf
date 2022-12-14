#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"


char *readline(const char *prompt) {
    int limit = 256;
    char *str = safe_malloc(limit);
    printf("%s", prompt);
    int out = scanf("%255[^\n]", str);
    if (out == -1) {
        return NULL;
    }
    scanf("%*c");
    return str;
}

