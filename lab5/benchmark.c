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
int main() {
    Subscriber *arr = generate_subs(100);
    printf("0: %d\n1: %d\n", (arr[0]).timestamp, (arr[1]).timestamp);
    printf("%d", RAND_MAX);
    return 0;
}