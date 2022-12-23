#ifndef SORTS_H
#define SORTS_H

int compare_names(Subscriber a, Subscriber b);

int compare_phones(Subscriber a, Subscriber b);

int compare_timestamps(Subscriber a, Subscriber b);

int make_int(char *phone);

void qsortpp(Subscriber *arr, size_t size, int sort_type);

void odd_even_sort(Subscriber *arr, size_t size, int(*compar)(Subscriber, Subscriber));

#endif SORTS_H