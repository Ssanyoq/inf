#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *read_list() {
    char c = getchar();
    int skipping = 0;
    List *out = (List *)malloc(sizeof(List));
    Item *prev = NULL;
    Item *cur;
    Item *last_before_sep = NULL;
    while (c != '\n' && c != EOF) {
        if (c == ' ' || c == '\t') {
            if (skipping) {
                goto end_of_loop;
            }
            skipping = 1;
            last_before_sep = prev;
        } else {
            skipping = 0;
        }
        cur = (Item *)malloc(sizeof(Item));
        cur->symb = c;
        if (prev == NULL) {
            out->head = cur;
        } else {
            prev->ptr = cur;
        }
        prev = cur;
        end_of_loop:
        c = getchar();
    }
    if (skipping) {
        free(cur);
        last_before_sep->ptr = NULL;
    }
    if (prev == NULL) {
        free(out);
        return NULL;
    }
    cur->ptr = NULL;
    return out;
}

void print_list(List *list) {    
    Item *cur_item = list->head;
    while (cur_item != NULL)
    {
        printf("%c", cur_item->symb);
        cur_item = cur_item->ptr;
    }   
}