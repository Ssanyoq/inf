#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mystruct.h"
#include "files.h"
#include "sorts.h"


// sort: q, o, s
// args: <read file> <write file> -s <sorting type>\
// -r <1|0 - reversed or not> -f <field for sorting>
int main(int argc, char *argv[]) {
    int c;
    void (* sort)(Subscriber *, int, int(*)(const void *, const void *)) = qsortpp; // 0 - qsort, 1 - odd even, 2 - Shell
    int reversed = 0;
    int (* compar)(const void *, const void *); // 0 - name, 1 - phone, 2 - timestamp
    compar = compare_names;
    char arg;
    while ((c = getopt(argc, argv, "s:r:f")) != -1) {
        switch (c) {
            case 's':
                arg = optarg[0];
                switch (arg) {
                    case 'q':
                        sort = qsortpp;
                        break;
                    case 'o':
                        sort = odd_even_sort;
                        break;
                    case 's':
                        sort = shell_sort;
                        break;
                    default:
                        fprintf(stderr, "Error: sorting of this type does not exist\n");
                        return 1;
                }
                break;
            case 'r':
                if (optarg[0] == '0' || optarg[0] == '1') {
                    reversed = (int)optarg[0];
                } else {
                    fprintf(stderr, "Error: incorrect -r argument\n");
                    return 1;
                }
                break;
            case 'f':
                switch (optarg[0])
                {
                    case '0':
                        compar = compare_names;
                        if (reversed) {
                            compar = rev_names;
                        }
                        break;
                    case '1':
                        compar = compare_phones;
                        if (reversed) {
                            compar = rev_phones;
                        }
                        break;
                    case '2':
                        compar = compare_timestamps;
                        if (reversed) {
                            compar = rev_timestamps;
                        }
                        break;
                    default:
                        fprintf(stderr, "Error: incorrect -f argument\n");
                        return 1;
                }
                break;
            default:
                fprintf(stderr, "Error: incorrect argument given\n");
                return 1;
        }
    }

    // postitional
    if (optind >= argc) {
        fprintf(stderr, "Error: missing positional arguments\n");
        return 1;
    }
    char *read_file = argv[optind];
    if (!read_file) {
        fprintf(stderr, "Error: missing required argument\n");
        return 1;
    }
    if (access(read_file, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: read file does not exist\n");
        return 1;
    }
    optind++;
    if (optind >= argc) {
        fprintf(stderr, "Error: missing positional arguments\n");
        return 1;
    }
    char *write_path = argv[optind];
    if (!write_path) {
        fprintf(stderr, "Error: missing required argument\n");
        return 1;
    }
    if (access(write_path, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: write file does not exist\n");
        return 1;
    }

    int len;
    Subscriber *arr = parse_file(read_file, &len);
    clock_t start = clock();
    sort(arr, len, compar);
    clock_t end = clock();
    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    write_file(write_path, arr, len);
    free_arr(arr, len);
    return 0;
}
