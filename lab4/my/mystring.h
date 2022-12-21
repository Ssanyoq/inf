#ifndef MYSTRING_H
#define MYSTRING_H

size_t strlen(const char *s);

char *strchr(const char *s, int c);

char *strtok(char *restrict str, const char *restrict sep);

char *strdup(const char *s1);

char *strcat(char *restrict s1, const char *restrict s2);

int tolower(int c);

#endif