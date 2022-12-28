#ifndef FILES_H
#define FILES_H

char *freadline(FILE *readfile);

Subscriber *parse_file(char *path, int *size);

void write_file(char *path, Subscriber *arr, int size);

void free_arr(Subscriber *arr, int len);

#endif
