#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"
#include "mystring.h"

#define BUFSIZE 256


char *readline(const char *prompt) {
    char *str = safe_malloc(0);
    int len = 0;
    printf("%s", prompt);
    char *buf = safe_malloc(BUFSIZE);
    int buf_len;
    int out;
    while (1) {
        out = scanf("%.[^\n]%n", BUFSIZE - 1, buf, buf_len);
        if (out == -1) {
            return NULL;
        }
        if (out == 0) {
            break;
        }
        len += buf_len;
        str = safe_realloc(str, len);
        str = strcat(str, buf);
        free(buf);
    }

    scanf("%*c");
    return str;
}

