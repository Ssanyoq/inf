#ifndef SORTS_H
#define SORTS_H

int compare_names(const void *a, const void *b);

int rev_names(const void *a, const void *b);

int compare_phones(const void *a, const void *b);

int rev_phones(const void *a, const void *b);

int compare_timestamps(const void *a, const void *b);

int rev_timestamps(const void *a, const void *b);

void odd_even_sort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

void shell_sort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

#endif