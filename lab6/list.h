#ifndef LIST_H
#define LIST_H

typedef struct Item
{
    char symb;
    struct Item *ptr;
} Item;

typedef struct
{
    Item *head;
} List;

void free_list(List *l);

#endif
