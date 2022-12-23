#include <stdio.h>
#include <struct.h> 
#include "list.h"
#include "io.h"

#define N 4

void process(List *l) {
    Item *cur = l->head;
    int i;
    int m_pos;
    int was_sep = 1;
    Item *m;
    Item *last;
    while (cur != NULL)
    {
        if (cur->symb == ' ') {
        } else {
            if (was_sep) { // new word
                was_sep = 0;
                i = 0;
                last = cur;
                m = cur;
                m_pos = 0;
            } else {
                i++;
                last = cur;
                if (i - m_pos > N) {
                    m_pos++;
                    m = m->ptr;
                }
            }
        }
    }
    
}

int main() {
    List *list = read_list();
    while (list != NULL) {
        printf("Given string: \"");
        print_list(list);
        printf("\"\n");
        process(list);

        free_list(list);
        list = read_list();
    }
    return 0;
}