#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "mem.h"
#include "sorts.h"
#include "mystruct.h"
#include "files.h"

#define ERROR_CODE 1

void err_bad_input() {
    fprintf(stderr, "Wrong parameters given\n");
}

char *rand_name(int size) {
    // generates a string with symbols from 'a' to 'z'
    char *str = (char *)safe_malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        // rand int from 97 to 122
        char symb = (char)(97 + rand() % 26);
        str[i] = symb;
    }
    return str;
}

char *rand_phone(int size) {
    // generates a string with symbols from '0' to '9'
    char *str = (char *)safe_malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        // rand int from 48 to 57
        char symb = (char)(48 + rand() % 10);
        str[i] = symb;
    }
    return str;
}

Subscriber *generate_subs(int amt) {
    // sub: {name: '', phone: '', timestamp: random int [0, 1.000.000] (or < 1000000, depends on RAND_MAX)
    Subscriber *arr;
    arr = (Subscriber *)safe_malloc(amt * sizeof(Subscriber));
    for (int i = 0; i < amt; i++) {
        Subscriber cur;
        cur.name = rand_name(50);
        cur.phone = rand_phone(16);
        cur.timestamp = rand() % 1000001;
        arr[i] = cur;
    }
    return arr;
}
int main(int argc, char **argv) {
    void (*sort)(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) = qsort;
    int reversed = 0;
    int (*compar)(const void *, const void *);
    int c;
    int field = 1; // 1 - name, 2 - phone, 3 - timestamp
    while ((c = getopt(argc, argv, "s:r:f")) != -1) {
        switch (c)
        {
        case 's': // sorting type
            switch (optarg[0])
            {
            case 'q':
                sort = qsort;
                break;
            case 'o':
                sort = odd_even_sort;
                break;
            case 's':
                sort = shell_sort;
                break;
            default:
                err_bad_input();
                return ERROR_CODE;
                break;
            }
            break;
        case 'r': // reversed or not
            switch (optarg[0])
            {
            case '1':
                reversed = 1;
                break;
            case '0':
                reversed = 0;
                break;
            default:
                err_bad_input();
                return ERROR_CODE;
                break;
            }
            break;
        case 'f': // field for sorting
            switch (optarg[0])
            {
            case '1':
                field = 1;
                break;
            case '2':
                field = 2;
                break;
            case '3':
                field = 3;
                break;
            default:
                err_bad_input();
                return ERROR_CODE;
                break;
            }
            break;
        default: // bad input
            err_bad_input();
            return ERROR_CODE;
            break;
        }
    } // optargs end


    if (optind >= argc) {
        err_bad_input();
        return ERROR_CODE;
    }
    
    char *str_part = argv[optind];
    if (!str_part) {
        err_bad_input();
        return ERROR_CODE;
    }
    char *marker;
    int len = strtol(str_part, &marker, 10); 
    if (marker == str_part) { // bad str to long
        printf("Array's length not found.\n");
        return ERROR_CODE;
    } else if (len <= 0) {
        printf("Bad number\n");
        return ERROR_CODE;
    }


    optind++;
    if (optind >= argc) {
        err_bad_input();
        return ERROR_CODE;
    }
    str_part = argv[optind];
    if (!str_part) {
        err_bad_input();
        return ERROR_CODE;
    }
    int arr_amt = strtol(str_part, &marker, 10); 
    if (marker == str_part) { // bad str to long
        printf("Array's length not found.\n");
        return ERROR_CODE;
    } else if (arr_amt <= 0) {
        printf("Bad number\n");
        return ERROR_CODE;
    }


    // comparators
    switch (field)
    {
    case 1:
        if (reversed) {
            compar = compare_names;
        } else {
            compar = rev_names;
        }
        break;
    case 2:
        if (reversed) {
            compar = compare_phones;
        } else {
            compar = rev_phones;
        }
        break;
    case 3:
        if (reversed) {
            compar = compare_timestamps;
        } else {
            compar = rev_timestamps;
        }
        break;
    default:
        printf("Impossible\n");
        exit(1);
        break;
    }

    // char *a = rand_phone(100);
    // printf("%s\n", a);
    // printf("size: %d, amt: %d\n", len, arr_amt);
    // Subscriber *arr = generate_subs(amt);
    // time_t start = clock();
    // sort(arr, amt, sizeof(Subscriber), compare_timestamps);
    // time_t end = clock();
    // printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
    // free_arr(arr, amt - 1);

    return 0;
}