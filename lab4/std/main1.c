#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "../mem.h"

const char vowels[7] = {'a','e','i','o','u','y', '\0'};


int is_vowel(char c) {
    c = tolower(c);
    if (strchr(vowels, c) == NULL) {
        return 0;
    } else {
        return 1;
    }
}
void print_string(char *str, char c){
    printf("%c", c);
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }
    printf("%c", c);
}

char *process(char* str) {
    int len = strlen(str);
    int new_len = 0;
    char* new_str = safe_malloc(len * 2 + 1);
    int was_sep = 0;
    for (int i = 0; i < len; i++) {
        if (is_vowel(str[i])) {
            new_str[new_len] = str[i];
            new_len++;
        }
        if (str[i] == ' ' || str[i] == '\t') {
            if (was_sep) {
                continue;
            }
            was_sep = 1;
            new_str[new_len] = ' ';
            new_len++;
            continue;
        }
        was_sep = 0;
        new_str[new_len] = str[i];
        new_len++;
    }
    new_str[new_len] = '\0';
    new_str = safe_realloc(new_str, new_len + 1);
    return new_str;
}

int main() {
    char *str;
    str = readline("Input string: ");
    while (str != NULL) {
        printf("Current string: ");
        print_string(str, '"');
        clock_t start = clock();
        char *new_str = process(str);
        clock_t end = clock();
        printf("\nNew string: ");
        print_string(new_str, '"');
        printf("\n");
        printf("Processed in %lf s.\n", (double)(end - start) / CLOCKS_PER_SEC);
        free(str);
        free(new_str);
        str = readline("Input string: ");

    }
    return 0;
}
