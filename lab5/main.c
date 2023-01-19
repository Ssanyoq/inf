#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void err_bad_input() {
    fprintf(stderr, "")
}

// sorts: -s q|o|s 
// reversed: -r 1|0
// field for sorting: -f 1|2|3
// readfile, writefile
int main(int argc, int **argv) {
    int (*sort)(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *)) = qsort;
    int reversed = 0;
    int (*compar)(const void *, const void *);
    int c;
    while ((c = getopt(argc, argv, "s:r:f")) != -1) {
        switch (c)
        {
        case 's': // sorting type
            switch (optarg[0])
            {
            case /* constant-expression */:
                /* code */
                break;
            
            default:
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

                break;
            }
            break;
        case 'f': // field for sorting
            switch (optarg[0])
            {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            default:
                break;
            }
            break;
        default: // bad input
            break;
        }
    }
}