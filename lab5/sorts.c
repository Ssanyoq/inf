#include "mystruct.h"
#include "sorts.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a > b => 1; a == b => 0; a < b => -1

int compare_names(const void *a, const void *b) {
    // Compares by names
    return strcmp(((Subscriber *)a)->name, ((Subscriber *)b)->name);
}

int rev_names(const void *a, const void *b) {
    return compare_names(b, a);
}

int compare_phones(const void *a, const void *b) {
    // Compares by names
    return strcmp(((Subscriber *)a)->phone, ((Subscriber *)b)->phone);
}

int rev_phones(const void *a, const void *b) {
    return compare_names(b, a);
}

int compare_timestamps(const void *a, const void *b) {
    int num1 = ((Subscriber *)a)->timestamp;
    int num2 = ((Subscriber *)a)->timestamp;
    if (num1 > num2) {
        return 1;
    } else if (num1 == num2) {
        return 0;
    } else {
        return -1;
    }
}

int rev_timestamps(const void *a, const void *b) {
    return compare_timestamps(b, a);
}

void odd_even_sort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) {
    // nel - length
    // width - sizeof
    Subscriber *arr;
    arr = (Subscriber *)base;
    short is_sorted = 0;
    Subscriber buf;
    while (!is_sorted)
    {
        is_sorted = 1;

        // odd index
        for (int i = 1; i <= nel - 2; i = i + 2) {
            if (compar((void *)(&(arr[i])), (void *)(&(arr[i + 1]))) == 1) {
                buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
                is_sorted = 0;
            }
        }
 
        // even index
        for (int i = 0; i <= nel - 2; i = i + 2) {
            if (compar((void *)(&(arr[i])), (void *)(&(arr[i + 1]))) == 1) {
                buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
                is_sorted = 0;
            }
        }
    }
}