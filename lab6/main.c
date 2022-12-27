#include <stdio.h>
#include <struct.h> 
#include "list.h"
#include "io.h"

#define N 4

void process(List *l) {
    Item *cur = l->head;

    Item *word_start = NULL;
    Item *word_end = NULL;
    Item *marker = NULL;
    Item *symb_before_word = NULL;
    int word_i;
    int word_len = 0;
    int marker_i;

    while (cur != NULL) {
        if (cur->symb != ' ') {
            if (word_len != 0) {
                word_end = cur;
                if (word_i - marker_i > N) {
                    marker = marker->ptr;
                    marker_i++;
                }
            } else {
                word_end = cur;
                word_start = cur;
                marker = cur;
            }
            word_len++;
            word_i++;
        } else {
            if (word_len != 0) {
                if (N < word_len) {
                    // ez
                } else {
                    int cur_n = N % word_len;
                    if (word_i - marker_i < cur_n) {
                        marker_i = 0;
                        marker = word_start;
                    }
                    while (word_i - marker_i != cur_n)
                    {
                        marker = marker->ptr;
                        marker_i++;
                    }
                        
                }
                if (symb_before_word != NULL) {
                    symb_before_word->ptr = marker->ptr;
                } else {
                    l->head = marker->ptr;
                }
                marker->ptr = cur;
                word_end->ptr = word_start;
                if (word_start == l->head) {
                    l->head = marker;
                }
                word_len = 0;
                marker_i = 0;
                word_i = 0;

            }
            symb_before_word = cur;
        }


        cur = cur->ptr;
    }
    printf("normal\n");
    if (word_len != 0) {
        if (N < word_len) {
            if (symb_before_word != NULL) {
                symb_before_word->ptr = marker->ptr;
            } else {
                l->head = marker->ptr;
            }
            marker->ptr = cur;
            word_end->ptr = word_start;
            if (word_start == l->head) {
                l->head = marker;
            }
        }
    }
    
}

int main() {
    List *list = read_list();
    while (list != NULL) {
        // printf("Given string: \"");
        // print_list(list);
        // printf("\"\n");
        process(list);
        printf("Processed: \"");
        print_list(list);
        printf("\"\n");
        free_list(list);
        list = read_list();
        printf("\n");
    }
    return 0;
}