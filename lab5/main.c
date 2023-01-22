#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "mystruct.h"
#include "files.h"
#include "sorts.h"

#define ERROR_CODE 1

void err_bad_input() {
    fprintf(stderr, "Wrong parameters given\n");
}

// sorts: -s q|o|s 
// reversed: -r 1|0
// field for sorting: -f 1|2|3
// readfile, writefile
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
    
    char *read_path = argv[optind];
    if (!read_path) {
        err_bad_input();
        return ERROR_CODE;
    }
    if (access(read_path, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: read file does not exist\n");
        return ERROR_CODE;
    }
    optind++;
    if (optind >= argc) {
        err_bad_input();
        return ERROR_CODE;
    }
    char *write_path = argv[optind];
    if (!write_path) {
        err_bad_input();
        return ERROR_CODE;
    }
    if (access(write_path, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: write file does not exist\n");
        return ERROR_CODE;
    }

    int len;
    Subscriber *arr = parse_file(read_path, &len);
    sort(arr, len, sizeof(Subscriber), compar);
    printf("ayy off sorts\n");
    write_file(write_path, arr, len);
    free_arr(arr, len);
    return 0;
}