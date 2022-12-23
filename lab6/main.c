#include <stdio.h>
#include <struct.h> 
#include "list.h"
#include "io.h"

int main() {
    List *list = read_list();
    print_list(list);
    return 0;
}