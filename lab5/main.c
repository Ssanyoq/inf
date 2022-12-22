#include <unistd.h>
#include <stdio.h>
#include "mystruct.h"

// sort: qs, oe, sh

// args: <read file> <write file> -s <sorting type> -silent

int main(int argc, char **argv) {
    int c
    int was_sorting = 0;
    int sort_type = 0; // 0 - qsort, 1 - odd even, 2 - Shell
    while ((c = getopt(argc, argv, "")) != -1) {
        switch (c)
        {
        case 's':

            break;
        default:
            break;
        }
    }
}