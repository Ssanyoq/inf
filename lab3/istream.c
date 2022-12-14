#include <stdio.h>
#include "istream.h"
#include "menu.h"
#include "arrays.h"
#include "printables.h"
#include <stdlib.h>

void enter_to_continue() {
    printf("Press ENTER to continue...");
    while (getchar() != '\n');
}

void clear_buff() {
    scanf("%*[^\n]");
}

int input_u(int *var) { 
    int out = input_d(var);
    if (out == -1) { 
        return -1;
    }
    while (*var < 0)
    {
        printf("Bad input, try again: ");
        out = input_d(var);
        if (out == -1) {
            return -1;
        }
    }
    return 0;
    
}

// int input_u(int *var) {
//     // doesn't clear anything
//     char t;
//     int inp;
//     int out = scanf("%d%c", &inp, &t);
//     while (out != 2 || t != '\n' || inp < 0) {
//         if (out == -1){
//             return -1;
//         }
//         printf("Bad input, try again: ");
//         if (out != 2 || t !='\n') {
//             clear_buff();
//         }
//         out = scanf("%d%c", &inp, &t);
        
//     }
//     *var = inp;
//     return 0;
// }

int input_d(int *var) {
    // doesn't clear anything
    char t;
    int inp;
    int out = scanf("%d%c", &inp, &t);
    while (out != 2 || t != '\n') {
        if (out == -1){
            return -1;
        }
        printf("Bad input, try again: ");
        clear_buff();
        out = scanf("%d%c", &inp, &t);
    }
    *var = inp;
    return 0;
}

int input_arr(int **arr, int *len, int *bytes_size) {
    int out;
    out = user_realloc(arr, bytes_size);
    if (out == -1) { 
        return -1;
    }
	printf("Input size of an array: ");
	out = input_u(len);
    if (out == -1) {
            return -1;
    }
    while (*len * sizeof(int) > *bytes_size) {
        printf("Not enough memory allocated for this array length\n");
        printf("(allocated %d bytes, size of int = %lu)\n", *bytes_size, sizeof(int));
        printf("Try again: ");
        out = input_u(len);
        if (out == -1) {
            return -1;
        }
    }
	for (int i = 0; i < *len; i++) {
		printf("Input an integer number: ");
		out = input_d(&((*arr)[i]));
        if (out == -1) {
            return -1;
        }
	}
    system("clear");
    printf("Array initialized successfully\n");
	return 0;
}
