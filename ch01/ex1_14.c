#include <stdio.h>

/* print a histogram of letter frequencies, both horizontally & vertically 
 * 'convert' all letters to upper case */

#define OFFSET 32 /* conversion factor for lc -> uc, ie, 'A' = 65, 'a' = 97 */
#define NUMLETTERS 26 

int main(int argc, char *argv[]) {
    int c, i, idx, maxlen, j;
    int letters[NUMLETTERS];

    for (i = 0; i < NUMLETTERS; ++i)
        letters[i] = 0;

    while ((c = getchar()) != EOF) {
        idx = c - 'A';
        if (idx >= 0 && idx <= 25) /* A-Z */
            ++letters[idx];
        else if (idx >= 32 && idx <= 57) /* a-z */
            ++letters[idx-OFFSET];
    }
    
    maxlen = 0;
    for (i = 0; i < NUMLETTERS; ++i) {
        if (letters[i] > maxlen)
            maxlen = letters[i];
    }

    /* horizontal */
    while (maxlen > 0) {
        for (i = 0; i < NUMLETTERS; ++i) {
            if (letters[i] >= maxlen) {
                printf(" x ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
        --maxlen;
    }

    printf("---");
    for (i = 0; i < NUMLETTERS; ++i)
        printf("---");
    printf("\n");

    for (i = 0; i < NUMLETTERS; ++i)
        printf(" %c ", i + 'A');
    printf("\n");

    /* vertical */
    printf("\n");
    for (i = NUMLETTERS-1; i >= 0; --i) {
        printf("%c | ", i + 'A');
        for (j = 0; j < letters[i]; ++j)
            printf("x");
        printf("\n");
    }

    return 0;
}
