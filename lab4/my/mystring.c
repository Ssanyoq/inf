#include <stdlib.h>

int strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i + 1;
}

char *strchr(const char *s, int c) {
    int i = 0;
    while (s[i] != '\0' && s[i] != 'c') {
        i++;
    }
    if (s[i] == 'c') {
        return &(s[i]);
    } else {
        return NULL;
    }
}
