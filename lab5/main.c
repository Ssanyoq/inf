#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

// sort: q, o, s
// args: <read file> <write file> -s <sorting type> -q <1|0 - quiet or not>\// -r <1|0 - reversed or not> -f <field for sorting>
int main(int argc, char *argv[]) {
    int c;
    int sort_type = 0; // 0 - qsort, 1 - odd even, 2 - Shell
    int 
    int quiet = 0;
    char arg;
    while ((c = getopt(argc, argv, "s:q")) != -1) {
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
                }
                break;
            case 'q':
                if (optarg[0] == '1' || optarg[0] == '2') {
                    quiet = (int)optarg[0];
                } else {
                    fprintf(stderr, "Error: incorrect -q argument\n");
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Error: incorrect argument given\n");
                return 1;
        }
        printf("???\n");
    }
    printf("%d\n",c);

    // postitional

    FILE *read_file = (FILE *)argv[optind];
    if (access((char *)read_file, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: read file does not exist\n");
        return 1;
    }

    FILE *write_file = (FILE *)argv[optind];
    if (access((char *)write_file, F_OK) == 0) {
        // gut
    } else {
        fprintf(stderr, "Error: write file does not exist\n");
        return 1;
    }
    printf("success?");    
    return 0;
}
