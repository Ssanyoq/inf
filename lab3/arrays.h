#ifndef ARRAYS_H
#define ARRAYS_H

short is_good_num(int num);

int process(int **arr, int *len, int **arr_to_delete, int *arrtd_len);

int insert_item(int **arr, int *len, int bytes_size);

int delete_item(int **arr, int *len);

#endif