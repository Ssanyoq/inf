#include <stdio.h>
#include <stdlib.h>
#include "istream.h"
#include "menu.h"
#include "mem.h"
#include "arrays.h"
#include "printables.h"


int insert_item_prints(int *arr, int *len, int bytes_size) {
    // if ((*len + 1) * sizeof(int) > bytes_size) {
    //     need_more_memory();
    //     return 2;
    // }
    printf("Input an index(natural number) to insert new element(len = %d): ", *len);
    int out = insert_item(arr, len, bytes_size);
    if (out == -1) {
        return -1;
    } if (out == 1) {
        need_more_memory();
        return 0;
    }
    prepare_out();
    
    system("clear");
    printf("Element inserted successfully\n");
    return out;
}

int delete_item_prints(int *arr, int *len) {
    if (*len == 0) {
        arr_not_initialized();
        return 0;
    }
    prepare_out();
    printf("Enter an index of element that you want to delete(len = %d): ", *len);
    int ind;
    int out = input_u(&ind);
    if (out == -1) {
        return -1;
    }
    out = delete_item(arr, len, ind);
    if (out == 1) {
        while (out != 0)
        {
            printf("Index out of range(len = %d), try again: ", *len);
            out = input_u(&ind);
            if (out == -1) {
                return -1;
            }
            out = delete_item(arr, len, ind);
        }
        
    }
    system("clear");
    printf("Element deleted successfully\n");
    return out;
}

int user_realloc(int **arr, int *bytes_size, int *len) {
    prepare_out();
    printf("Input an amount of elements that you want to\n");
    printf("have in your array(int size is %lu): ", sizeof(int));
    int inp;
    int out = input_u(&inp);
    if (out == -1) {
        return -1;
    }
    *arr = (int*)safe_realloc(*arr, inp * sizeof(int));
    *bytes_size = inp * sizeof(int);
    if (inp < *len) {
        *len = inp;
    }
    return 1;
}    

void print_arr(int *arr, unsigned int len, int bytes_size, short enter) {
    prepare_out();
    if (len == 0) {
        printf("Bytes allocated: %d\n", bytes_size);
        printf("Array is empty");
    } else {
        printf("int array, len: %u", len);
        if (bytes_size != -1) {
            printf(", bytes allocated: %db", bytes_size);
        }
        printf("\n[");
        for (int i = 0; i < len; i++) {
            printf("%d", arr[i]);
            if (i != len - 1) {
                printf(", ");
            }
        }
        printf("]");
    }
    printf("\n\n");
    if (enter) {
        enter_to_continue();
    }
}

int process_prints(int *arr, int *len) {
    if (*len == 0) {
        arr_not_initialized();
        return 0;
    }
    int *arr_to_delete = safe_malloc(*len);
    int arrtd_len = 0;
    int out = process(arr, len, arr_to_delete, &arrtd_len);
    if (out == 1) { 
        arr_not_initialized();
        return 2;
    }
    system("clear");
    printf("\n\nArray was processed.\n");
    printf("Sequence to be deleted: ");
    print_arr(arr_to_delete, arrtd_len, -1, 1);
    printf("\nNew array: ");
    print_arr(arr, *len, -1, 1);
    free(arr_to_delete);
    system("clear");
    printf("Array was processed successfully\n");
    return 0;
}

int menu() {
    int *arr = safe_malloc(0);
    int tmp = 0;
    int *len = &tmp;
    system("clear");
    printf("\n");
    short quitting = 0;
    int bytes_size = 0;
    int out;
    while (!quitting) {
        printf("\n");
        printf("Choose any option:\n\n");
        printf("1 - Initialize(or reinitialize) an array\n");
        printf("2 - Insert new element into an array\n");
        printf("3 - Delete an element from an array\n");
        printf("4 - Process an array\n");
        printf("5 - Print out an array\n");
        printf("6 - Reallocate memory for an array\n");
        printf("\n0 - Quit\n");
        printf("\n");
        
        printf("Input: ");
        int inp;
        out = input_u(&inp);
        if (out == -1) { 
            quitting = 1;
            continue;
        }

        while (inp > 6) {
            printf("Operation with this number doesn't exist, try again: ");
            out = input_u(&inp);
        }
        
        switch (inp) {
            case 0:
                // quit
                quitting = 1;
                continue;
                break;
            case 1:
                // initialize
                out = input_arr(&arr, len, &bytes_size);
                break;
            case 2:
                // insert
                out = insert_item_prints(arr, len, bytes_size);
                break;
            case 3:
                // delete
                out = delete_item_prints(arr, len);
                break;
            case 4:
                out = process_prints(arr, len);
                // process
                break;
            case 5:
                print_arr(arr, *len, bytes_size, 1);
                system("clear");
                printf("\n");
                // print
                break;
            case 6:
                // reallocate
                user_realloc(&arr, &bytes_size, len);
                system("clear");
                printf("Memory allocated successfully\n");
                break;
        }
        quitting = out;
    }
    free(arr);
    return quitting;
}
