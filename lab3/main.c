#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "menu.h"

int main() {
    int out = menu();
    if (out == -1) {
        printf("\nEOF detected\n");
        return 1;
    } 
    return 0;
}   

