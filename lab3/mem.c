#include <stdlib.h>
#include <stdio.h>

int *safe_realloc(int *arr, int new_size) {

    // printf("ns: %d a[0]=%d\n", new_size, arr[0]);
    arr = (int*)realloc(arr, new_size);
    if (!arr) {
        printf("Error occurred while reallocating memory\n");
        return NULL;
    }

    return arr;

}

int *safe_malloc(int len) {

    int *arr = (int*)malloc(len * sizeof(int));
    if (!arr) {
        printf("Error occurred while allocating memory\n");
        return NULL;
    }
    
    return arr;
}