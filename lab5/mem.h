#ifndef MEM_H
#define MEM_H

void *safe_malloc(int len);

void *safe_realloc(void *ptr, int len);

#endif