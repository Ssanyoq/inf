#include "mystruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a > b => 1; a == b => 0; a < b => -1

int compare_names(Subscriber a, Subscriber b) {
    // Compares by names
    return strcmp(a.name, b.name);
}

int compare_phones(Subscriber a, Subscriber b) {
    int num1 = make_int(a.phone);
    int num2 = make_int(b.phone);
    if (num1 > num2) {
        return 1;
    } else if (num1 == num2) {
        return 0;
    } else {
        return -1;
    }
}

int compare_timestamps(Subscriber a, Subscriber b) {
    int num1 = a.timestamp
    int num2 = b.timestamp
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

void qsortpp(Subscriber *arr, size_t size, int sort_type) { // pp for plus plus
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