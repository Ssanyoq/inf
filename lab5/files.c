#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystruct.h"

Subscriber *parse_file(char *path) {
    FILE *readfile = fopen(path, "r");
    printf("here\n");
    char *inp;
    char *str_part;
    fscanf(readfile, "%s", inp);
    long len = strtol(inp, &str_part, 10);
    printf("len: %d\n", len);
    char *a; 
    fscanf(readfile, "%s", a);
    printf("%s\n", a);
}
