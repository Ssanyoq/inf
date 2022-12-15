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
    } // warning, что делать((((((
}

int tolower(int c) {
    // 'A' - 65 in ASCII, 'Z' - 90
    // 'a' - 97 <=> upper + 32
    if (c >= 65 && c <= 90) {
        return c + 32;
    }
    return c;
}   