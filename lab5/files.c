#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystruct.h"
#include "mem.h"

char *freadline(FILE *readfile) {
    char *ptr = (char *)safe_malloc(1 * sizeof(char));
    char buf[256];

    int n, len = 0, buf_len;
    *ptr = '\0';
    do {
        n = fscanf(readfile, "%255[^\n]%n", buf, &buf_len);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0)
            fscanf(readfile, "%*c");
        else {
            len += buf_len;
            ptr = (char *)safe_realloc(ptr, (len + 1) * sizeof(char));
            strcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}

int check_name(char *name) {
    // not "", not only ' '
    // 1 - good, 0 - bad
    int len = strlen(name);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!(name[i] <= 'Z' && name[i] >= 'A') && !(name[i] >= 'a' && name[i] <= 'z')) {
            if (name[i] != ' ' && name[i] != '\t') { // if not in alphabet, then it should be either ' ' or '\t'
                return 0;
            }
        }
    }
    return 1;
}

int check_phone(char *phone) {
    // != "", only 1 '+' in the beginning, 
    // only spaces and digits after it
    int len = strlen(phone);
    if (len == 0) {
        return 0;
    }
    short was_plus = 0;
    int symb_amt = 0;
    int were_digs = 0;
    for (int i = 0; i < len; i++) {
        if (phone[i] == '+') {
            if (was_plus && were_digs) {
                return 0;
            }
            was_plus = 1;
        } else if ('0' <= phone[i] && phone[i] <= '9') {
            were_digs = 1;
        } else if (phone[i] != ' ' && phone[i] != '\t') {
            return 0;
        }
        symb_amt++;
        if (symb_amt > 16) {
            return 0;
        }
    }
    if (!were_digs) {
        return 0;
    }
    return 1;
}

int check_timestamp(char *timestamp) {
    int len = strlen(timestamp);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if ('0' <= timestamp[i] && timestamp[i] <= '9') {
        } else {
            return 0;
        }
    }
    return 1;
}

Subscriber *parse_file(char *path, int *size) {
    FILE *readfile = fopen(path, "r");
    char *marker;
    char *str_part = freadline(readfile);

    int len = strtol(str_part, &marker, 10); 
    free(str_part);
    if (marker == str_part) { // bad str to long
        printf("File's length not found.\n");
        return NULL;
    }    

    // printf("length before: %d\n", len); // FOR DEBUG
    Subscriber *out = (Subscriber *)malloc(len * sizeof(Subscriber));
    int real_i = 0;
    int i = 0;
    int new_len = len;
    for (; i < len; i++) {
        char *name = freadline(readfile);
        char *phone = freadline(readfile);
        char *timestamp = freadline(readfile);
        if (!check_name(name) || !check_phone(phone) || !check_timestamp(timestamp)) {
            printf("Incorrect element No.%d, won't be included in the array\n", i + 1);
            new_len--;
            continue;
        }
        char *m;
        int ts = strtol(timestamp, &m, 10);
        free(timestamp);
        Subscriber cur;
        cur.name = name;
        cur.phone = phone;
        cur.timestamp = ts;
        out[real_i] = cur;
        real_i++;
    }
    if (i != real_i) {
        out = (Subscriber *)safe_realloc(out, (new_len) * sizeof(Subscriber));
    }
    fclose(readfile);
    // printf("len after: %d, i: %d, real i:%d, new_len: %d \n", len, i, real_i, new_len); // FOR DEBUG
    *size = new_len;
    return out;
}

void write_file(char *path, Subscriber *arr, int size) {
    // printf("in writing\n");
    FILE *wfile = fopen(path, "w");
    for (int i = 0; i < size; i++) {
        fprintf(wfile, "%s\n", arr[i].name);
        fprintf(wfile, "%s\n", arr[i].phone);
        fprintf(wfile, "%d\n", arr[i].timestamp);
    }
    fclose(wfile);
}

void free_arr(Subscriber *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i].name != NULL) {
            free(arr[i].name);
        }
        if (arr[i].phone != NULL) {
            free(arr[i].phone);
        }
    }
    free(arr);
}