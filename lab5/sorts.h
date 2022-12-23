#ifndef SORTS_H
#define SORTS_H

int compare_names(Subscriber a, Subscriber b);

int compare_phones(Subscriber a, Subscriber b);

int compare_timestamps(Subscriber a, Subscriber b);

int make_int(char *phone);

void qsortpp(Subscriber *arr, int size, int sort_type);

void odd_even_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber));

void shell_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber));

#endif
