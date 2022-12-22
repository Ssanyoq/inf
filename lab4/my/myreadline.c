#include <stdlib.h>
#include <stdio.h>
#include "../mem.h"
#include "mystring.h"

char *readline(const char *prompt) {
    printf("%s", prompt);
    char *ptr = (char *) malloc(sizeof(char));
    char buf[81];
    int n, len = 0, bufLen;
    *ptr = '\0';
    do {
        printf("?");
        n = scanf("%80[^\n]%n", buf, &bufLen);
        printf("!");
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0)
            scanf("%*c");
        else {
            len += bufLen;
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);
        }
    } while (n > 0);
    return ptr;
}
// char *readline(const char *prompt) {
    
//     char *ptr = safe_malloc(1);
//     char buf[81];

//     printf("%s", prompt);

//     int n, len = 0, buf_len;
//     *ptr = '\0';
//     do {
//         printf("?");
//         n = scanf("%80[^\n]%n", buf, &buf_len);
//         printf("!");
//         if (n < 0) {
//             free(ptr);
//             ptr = NULL;
//             continue;
//         }
//         if (n == 0)
//             scanf("%*c");
//         else {
//             len += buf_len;
//             ptr = (char *) realloc(ptr, len + 1);
//             strcat(ptr, buf);
//         }
//     } while (n > 0);
//     return ptr;
// }

