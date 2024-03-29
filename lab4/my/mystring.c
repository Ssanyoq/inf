#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"

size_t strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char *strchr(const char *s, int c) {
    int i = 0;
    while (s[i] != '\0' && s[i] != (char)c) {
        i++;
    }
    if (s[i] == c) {
        return (char *)&(s[i]);
    } else {
        return NULL;
    }
}

char *strtok(char *restrict str, const char * restrict sep) {
    static char *start;

    if (str != NULL) {
        start = str;
    }
    if (start == NULL) {
        return NULL;
    }


    int i = 0;
    
    // Moving until separators end
    while ((strchr(sep, start[i]) != NULL) && (start[i] != '\0')) {
        i++;
    }
    char *word = &(start[i]);
    // Moving until separators start
    while ((strchr(sep, start[i]) == NULL) && (start[i] != '\0')) {
        i++;
    }
    if (i == 0 || start[i] == word[0]) { // 0 symbols || only separators
        return NULL;
    }
    if (start[i] == '\0') {
        start = NULL;
    } else {
        start[i] = '\0';
        start = &(start[i + 1]);
    }
    return word;
}

char *strdup(const char *s1) {
    int len = strlen(s1);
    char *new_s = safe_malloc(len + 1);
    int i = 0;
    for (; i < len; i++) {
        new_s[i] = s1[i];
    }
    new_s[i] = '\0';
    return new_s;
}

char *strcat(char *restrict s1, const char *restrict s2) {
    int s1_len = strlen(s1);
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[s1_len + i] = s2[i];
        i++;
    }
    s1[s1_len + i] = '\0';
    return s1;
}

int tolower(int c) {
    // 'A' - 65 in ASCII, 'Z' - 90
    // 'a' - 97 <=> lower = upper + 32
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}   
