#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"
#include "istream.h"
#include "mem.h"

short is_good_num(int num) {
    // 1 - good, 0 - not good
    if (num < 0) {
        num *= -1;
    }
   
    if (num % 10 == 0) {
        return 1;
    }

    int last_dig = num % 10;
    num = num / 10;
    while (num > 0) {
        if (num % 10 <= last_dig) {
            return 0;
        }
        last_dig = num % 10;
        num = num / 10;
    } 
    return 1;
}

int process(int *arr, int *len, int *arr_to_delete, int *arrtd_len) {
    if (*len == 0) {
        return 1;
    }
    for (int i = 0; i < *len; i++) {
        if (is_good_num(arr[i])) {
            arr_to_delete[*arrtd_len] = arr[i];
            (*arrtd_len)++;
            delete_item(arr, len, i);
            i--;
        }
    }
    return 0;
}

int insert_item(int *arr, int *len, int bytes_size) {
    if ((*len + 1) * sizeof(int) > bytes_size) {
        // not enough memory
        return 1;
    }
    int insert_index = 0;
    int out;
    if (*len != 0) {
        out = input_u(&insert_index);
        if (out == -1) {
            return -1;
        }
        if (insert_index > *len) {
            insert_index = *len;
            // printf("Chosen index was decreased to %d\n", insert_index);
        }
    }
    printf("Input an integer number - value of an element: ");
    int val;
    out = input_d(&val);
    if (out == -1) {
            return -1;
    }
    for (int i = *len - 1; i > insert_index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[insert_index] = val;
    (*len)++;
    return 0;
}



int delete_item(int *arr, int *len, int ind) {
    if (ind >= *len) {
        return 1;
    }
    for (int i = ind; i < *len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*len)--;
    return 0;
}
