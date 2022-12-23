#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystruct.h"

Subscriber *parse_file(char *path) {
    FILE *readfile = fopen(path, "r");
    int len;
    fscanf(readfile, "%d", len);
    printf("len: %d\n", len);
    char *a; 
    fscanf(readfile, "%s", a);
    printf("%s\n", a);
}