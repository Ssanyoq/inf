#ifndef SORTS_H
#define SORTS_H

int compare_names(const void *a, const void *b);

int rev_names(const void *a, const void *b);

int compare_phones(const void *a, const void *b);

int rev_phones(const void *a, const void *b);

int compare_timestamps(const void *a, const void *b);

int rev_timestamps(const void *a, const void *b);

int make_int(char *phone);

void qsortpp(Subscriber *arr, int size, int(*compar)(const void *, const void *));

void odd_even_sort(Subscriber *arr, int size, int(*compar)(const void *, const void *));

void shell_sort(Subscriber *arr, int size, int(*compar)(const void *, const void *));

#endif
