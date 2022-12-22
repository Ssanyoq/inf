#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

// sort: q, o, s
// args: <read file> <write file> -s <sorting type>\
// -r <1|0 - reversed or not> -f <field for sorting>
int main(int argc, char *argv[]) {
    int c;
    int sort_type = 0; // 0 - qsort, 1 - odd even, 2 - Shell
    int reversed = 0;
    int field = 0; // 0 - name, 1 - phone, 2 - 
    char arg;
    while ((c = getopt(argc, argv, "s:r:f")) != -1) {
        switch (c) {
            case 's':
                was_sorting = 1;
                arg = optarg[0];
                switch (arg) {
                    case 'q':
                        sort_type = 0;
                        break;
                    case 'o':
                        sort_type = 1;
                        break;
                    case 's':
                        sort_type = 2;
                        break;
                    default:
                        fprintf(stderr, "Error: sorting of this type does not exist\n");
                        return 1;
                break;
                }
            case 'r':
                if (optarg[0] == '0' || optarg[0] == '1') {
                    reversed = (int)optarg[0];
                } else {
                    fprintf(stderr, "Error: incorrect -r argument\n");
                    return 1;
                }
            case 'f':
                if (optarg[0] == '1' || optarg[0] == '2' || optarg[0] == '3') {
                    sort_type = (int)optarg[0];
                } else {
                    fprintf(stderr, "Error: incorrect -q argument\n");
                    return 1;
                }
            default:
                fprintf(stderr, "Error: incorrect argument given\n");
                return 1;
        }
    }

    // postitional

    FILE *read_file = (FILE *)argv[optind];
    if (!read_file) {
        fprintf(stderr, "Error: missing required argument");
        return 1;
    }
    if (access((char *)read_file, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: read file does not exist\n");
        return 1;
    }

    FILE *write_file = (FILE *)argv[optind];
    if (!write_file) {
        fprintf(stderr, "Error: missing required argument");
        return 1;
    }
    if (access((char *)write_file, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: write file does not exist\n");
        return 1;
    }
    printf("success?");    
    return 0;
}
