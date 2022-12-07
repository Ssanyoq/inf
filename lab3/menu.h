#ifndef MENU_H
#define MENU_H

int insert_item_prints(int *arr, int *len, int bytes_size);

int delete_item_prints(int *arr, int *len);

int user_realloc(int **arr, int *bytes_size);

void print_arr(int *arr, unsigned int len, int bytes_size, short enter);

int process_prints(int *arr, int *len);

int menu();

#endif
