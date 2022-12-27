#include <stdio.h>
#include <struct.h> 
#include "list.h"
#include "io.h"

#define N 10

void process(List *l) {
    Item *cur = l->head;

    Item *word_start = NULL;
    Item *word_end = NULL;
    Item *symb_before_word = NULL;
    int word_len = 0;
    
    while (cur != NULL) {
        if (cur->symb == ' ') {
            if (word_len != 0) {
                if (N % word_len == 0) {
                    goto skip; // ---------------
                }
                Item *m = word_start;
                for (int i = 0; i < word_len; i++) {
                    if (word_len - 1 - i == N % word_len){
                        break;
                    }
                    m = m->ptr;
                }
                if (symb_before_word == NULL) {
                    l->head = m->ptr;
                } else {
                    symb_before_word->ptr = m->ptr;
                }
                word_end->ptr = word_start;
                m->ptr = cur;
                skip: // -------------------------
                word_len = 0;
            }

            symb_before_word = cur;
        }
        else {
            if (word_len == 0) {
                word_start = cur;
            }
            word_len++;
            word_end = cur;
        }  
        cur = cur->ptr;
    }
    if (word_len != 0) {
        Item *m = word_start;
        for (int i = 0; i < word_len; i++) {
            if (word_len - 1 - i == N % word_len){
                break;
            }
            m = m->ptr;
        }
        if (symb_before_word == NULL) {
            l->head = m->ptr;
        } else {
            symb_before_word->ptr = m->ptr;
        }
        word_end->ptr = word_start;
        m->ptr = cur;
        word_len = 0;
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