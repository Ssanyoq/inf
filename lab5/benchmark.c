#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mem.h"
#include "sorts.h"
#include "mystruct.h"

Subscriber *generate_subs(int amt) {
    // sub: {name: '', phone: '', timestamp: random int [0, 1.000.000] (or < 1000000, depends on RAND_MAX)
    Subscriber *arr;
    arr = (Subscriber *)safe_malloc(amt * sizeof(Subscriber));
    for (int i = 0; i < amt; i++) {
        Subscriber cur;
        cur.name = "";
        cur.phone = "";
        cur.timestamp = rand() % 1000001;
        arr[i] = cur;
    }
    return arr;
}
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Not enough parameters\n");
        return 1;
    }
    char *marker;
    int amt = strtol(argv[1], &marker, 10); 
    if (marker == argv[1]) { // bad str to long
        fprintf(stderr, "Bad 1st parameter\n");
        return 1;
    }
    char sort_type = argv[2][0];
    void (*sort)(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
    switch (sort_type)
    {
    case 'q':
        sort = qsort;
        break;
    case 's':
        sort = shell_sort;
        break;
    case 'o':
        sort = odd_even_sort;
        break;
    default:
        fprintf(stderr, "This type of sorting does not exist\n");
        return 1;
        break;
    }
    Subscriber *arr = generate_subs(amt);
    time_t start = RUSAGE_INFO_CURRENT
    // printf("%d", RAND_MAX);


    return 0;
}