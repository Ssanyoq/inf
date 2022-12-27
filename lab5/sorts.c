#include "mystruct.h"
#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a > b => 1; a == b => 0; a < b => -1

int compare_names(const void *a, const void *b) {
    // Compares by names
    return strcmp(((Subscriber *)a)->name, ((Subscriber *)b)->name);
}

int compare_phones(const void *a, const void *b) {
    int num1 = make_int(((Subscriber *)a)->phone);
    int num2 = make_int(((Subscriber *)b)->phone);
    if (num1 > num2) {
        return 1;
    } else if (num1 == num2) {
        return 0;
    } else {
        return -1;
    }
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

int make_int(char *phone) {
    int len = strlen(phone);
    int out = 0;
    for (int i = 0; i < len; i++) {
        if (phone[i] >= '0' && phone[i] <= '9') {
            out = out * 10 + (int)(phone[i] - '0');
        }
    }
    return out;
}

void qsortpp(Subscriber *arr, int size, int sort_type) { // pp for plus plus
    switch (sort_type) {// 0 - name, 1 - phone, 2 - timestamp
    case 0:
        qsort(arr, sizeof(Subscriber), size, compare_names);
        break;
    case 1:
        qsort(arr, sizeof(Subscriber), size, compare_phones);
        break;
    case 2:
        qsort(arr, sizeof(Subscriber), size, compare_timestamps);
        break;
    }
}

void odd_even_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber)) {
    short any_changes = 1;
    Subscriber buff;
    while (any_changes) {
        any_changes = 0;
        for (int i = 1; i < size - 1; i += 2) {
            if (compar(arr[i], arr[i + 1]) == 1) {
                buff = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buff;
                any_changes = 1;
            }
        }

        for (int i = 0; i < size - 1; i += 2) {
            if (compar(arr[i], arr[i + 1]) == 1) {
                buff = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buff;
                any_changes = 1;
            }
        }
    }
    
}

void shell_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber)) {
    for (int interval = size / 2; interval >= 1; interval = interval / 2) {
        for (int i = interval; i < size; i++) {
            int start_ind = i;
            int j = i;
            for (; j >= interval; j -= interval) {
                if (compar(arr[j - interval], arr[i]) == 1) {
                    arr[j] = arr[j - interval];
                } else {
                    break;
                }
            }
            arr[j] = arr[start_ind];
        }
    }
}
