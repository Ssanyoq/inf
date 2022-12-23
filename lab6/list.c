#include "list.h"
#include "stdlib.h"

void free_list(List *l) {
    Item *cur = l->head;
    Item *next;
    while (cur != NULL)
    {
        next = cur->ptr;
        free(cur);
        cur = next;
    }
    free(l);
}

