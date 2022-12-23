#ifndef LIST_H
#define LIST_H

typedef struct Item
{
    char symb;
    Item *ptr;
} Item;

typedef struct
{
    Item *head;
} List;

