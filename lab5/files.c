#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystruct.h"
#include "mem.h"

char *freadline(FILE *readfile) {
    char *ptr = safe_malloc(1);
    char buf[256];

    int n, len = 0, buf_len;
    *ptr = '\0';
    do {
        n = fscanf(readfile, "%255[^\n]%n", buf, &buf_len);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0)
            fscanf(readfile, "%*c");
        else {
            len += buf_len;
            ptr = safe_realloc(ptr, len + 1);
            strcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}

Subscriber *parse_file(char *path) {
    FILE *readfile = fopen(path, "r");
    printf("here\n");
    char *inp;
    char *str_part = freadline(readfile);
    long len = strtol(inp, &str_part, 10);
    printf("len: %d\n", len);
    char *a = freadline(readfile);
    printf("%s\n", a);
}
