#include <stdio.h>
#include <stdlib.h>
#include "printables.h"

void arr_not_initialized() {
    system("clear");
    printf("You must initialize array first\n");
}

void prepare_out() {
    system("clear");
    printf("\n\n");
}

void need_more_memory() {
    system("clear");
    printf("Not enough memory allocated for chosen operation\n");
}