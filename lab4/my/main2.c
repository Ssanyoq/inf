#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mem.h"
#include "mystring.h"
#include "myreadline.h"

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

char *process_word(char *word) {
    int i = 0;
    char *new_word = safe_malloc(strlen(word) * 2 + 1);
    int new_len = 0;
    while (word[i] != '\0') {
        if (is_vowel(word[i])) {
            new_word[new_len] = word[i];
            new_len++;
        }
        new_word[new_len] = word[i];
        new_len++;
        i++;
    }
    new_word[new_len] = '\0';
    new_len++;
    new_word = safe_realloc(new_word, new_len);
    return new_word;
}

char *process(char* str) {
    int len = strlen(str);
    int new_len = 0;
    char* new_str = safe_malloc(len * 2 + 1);
    new_str[0] = '\0';
    char *word = strtok(str, " \t");
    while (word != NULL) {
        word = process_word(word);
        if(new_str[0] != '\0') {
            new_str = strcat(new_str, " ");
        }
        new_str = strcat(new_str, word);
        free(word);
        word = strtok(NULL, " \t");
    }
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
