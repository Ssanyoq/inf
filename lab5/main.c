#include <unistd.h>
#include <stdio.h>
#include "mystruct.h"

// sort: q, o, s
// args: <read file> <write file> -s <sorting type> -q(quiet)

int main(int argc, char **argv) {
    int c;
    int was_sorting = 0;
    int sort_type = 0; // 0 - qsort, 1 - odd even, 2 - Shell
    int quiet = 0;
    while ((c = getopt(argc, argv, "")) != -1) {
        switch (c)
        {
        case 's':
            was_sorting = 1;
            switch (optarg)
            {
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
                fprintf(stderr, "Error: sorting of this type does not exist");
                return 1;
            }
            break;
        case 'q':
            quiet = 1;
            break;
        default:
            fprintf(stderr, "Error: %c is an incorrect argument", c);
            return 1;
        }
    }
    if (!was_sorting) {
        fprintf(stderr, "Error: sorting not specified");
        return 1;
    }
    return 0;
}