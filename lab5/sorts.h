#ifndef SORTS_H
#define SORTS_H

int compare_names(const void *a, const void *b);

int compare_phones(const void *a, const void *b);

int compare_timestamps(const void *a, const void *b);

int make_int(char *phone);

void qsortpp(Subscriber *arr, int size, int sort_type);

void odd_even_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber));

void shell_sort(Subscriber *arr, int size, int(*compar)(Subscriber, Subscriber));

#endif
