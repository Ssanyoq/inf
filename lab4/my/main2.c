#include <stdlib.h>
#include "main2.h"
#include "mystring.h"
#include "myreadline.h"
#include "../mem.h"
#include <stdio.h>

const char vowels[12] = {'a','e','i','o','u','y', 'A', 'E', 'I', 'O','U','Y'};

// char *safe_malloc(int len) {
//     char *str = (char*)malloc(len * sizeof(char));
//     if (!str) {
//         printf("Error occured while allocating memory\n");
//         return NULL;
//     }
//     return str;
// }

char *input_s() {
    char *inp;
    inp = readline();
    return inp;
}

int is_vowel(char c) {
    for (int i = 0; i < 6; i++) { // 6 - vowels amt
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
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
    char* new_str = safe_malloc(len * 2);
    for (int i = 0; i < len; i++) {
        if (is_vowel(str[i])) {
            new_str[new_len] = str[i];
            new_len++;
        }
        new_str[new_len] = str[i];
        new_len++;
    }
    return new_str;
}

int main() {
    char *str;
    str = input_s();
    printf("Current string: ");
    print_string(str, '"');
    char *new_str = process(str);
    printf("%d", strlen(new_str));
    printf("\nNew string: ");
    print_string(new_str, '"');
    printf("\n");
    free(str);
    free(new_str);
    return 0;
}
