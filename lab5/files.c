#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystruct.h"
#include "mem.h"

char *freadline(FILE *readfile) {
    char *ptr = safe_malloc(1 * sizeof(char));
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
            ptr = safe_realloc(ptr, (len + 1) * sizeof(char));
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
        if (name[i] != ' ' && name[i] != '\t') {
            return 1;
        }
    }
    return 0;
}

int check_phone(char *phone) {
    // != "", only 1 '+' in the beginning, 
    // only spaces and digits after it
    int len = strlen(phone);
    if (len == 0) {
        return 0;
    }
    short was_plus = 0;
    int dig_amt = 0;
    for (int i = 0; i < len; i++) {
        if (phone[i] == '+') {
            if (was_plus || dig_amt > 0) {
                return 0;
            }
            was_plus = 1;
        } else if ('0' <= phone[i] || phone[i] <= '9') {
            dig_amt++;
        } else if (phone[i] != ' ' && phone[i] != '\t') {
            return 0;
        }
        if (dig_amt > 16) {
            return 0;
        }
    }
    if (!dig_amt) {
        return 0;
    }
    return 1;
}

int check_timestamp(char *timestamp) {
    int len = strlen(phone);
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

Subscriber *parse_file(char *path) {
    FILE *readfile = fopen(path, "r");
    printf("here\n");
    char *marker;
    char *str_part = freadline(readfile);
    long len = strtol(str_part, &marker, 10);
    if (marker == str_part) {
        printf("File's length not found.\n");
        return NULL;
    }    
    printf("len: %ld\n", len);
    Subscriber *out = malloc(len * sizeof(Subscriber));
    for (int i = 0; i < len; i++) {
        char *name = freadline(readfile);
        char *phone = freadline(readfile);
        char *timestamp = freadline(readfile);
        if (!check_name(name) || !check_phone(phone) || !check_timestamp(timestamp)) {
            printf("Incorrect element No.%d, won't be included in the array\n", i);
        }
    }
}
