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
    // бяка (уже нет очевидно)
    printf("%s", str);
    printf("%c", c);
}

void process_word(char *word, char *new_str, int *len) {
    int i = 0;
    if (*len != 0) {
        new_str[*len] = ' ';
        (*len)++;
    }
    printf("NEW WORD:");
    print_string(word, '"');
    while (word[i] != '\0') {
        if (is_vowel(word[i])) {
            new_str[*len] = word[i];
            (*len)++;
        }
        new_str[*len] = word[i];
        (*len)++;
        i++;
    }
    new_str[*len] = '\0';
    (*len)++;
}

char *process(char* str) {
    str = strdup(str);
    int len = strlen(str);
    int new_len = 0;
    char* new_str = safe_malloc(len * 2 + 1);
    new_str[0] = '\0';
    char *word = strtok(str, " \t");
    while (word != NULL) {
        process_word(word, new_str, &new_len); // don't create tmp buffer
        // if(new_str[0] != '\0') {
        //     new_str = strcat(new_str, " "); // memcpy
        // }
        // new_str = strcat(new_str, word); // memcpy
        // free(word);
        word = strtok(NULL, " \t");
        printf("pop\n");
    }
    new_str = safe_realloc(new_str, new_len);
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
