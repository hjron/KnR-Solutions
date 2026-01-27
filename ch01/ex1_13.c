#include <stdio.h>

/* print a histogram of word lengths, both horizontally & vertically 
 * assume max word length of MAX-1 letters */

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */
#define MAX 15  /* max word length */

int main(int argc, char *argv[]) {
    int c, state, len, i, maxlen, j;
    int wlen[MAX];

    state = OUT;
    len = 0;
    for (i = 0; i < MAX; ++i)
        wlen[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (len > 0)
                ++wlen[len];
            len = 0;
        } else {
            state = IN;
            ++len;
        }
    }
    
    maxlen = 0;
    for (i = 0; i < MAX; ++i) {
        if (wlen[i] > maxlen)
            maxlen = wlen[i];
    }

    /* horizontal */
    while (maxlen > 0) {
        for (i = 0; i < MAX; ++i) {
            if (wlen[i] >= maxlen) {
                printf(" x ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
        --maxlen;
    }

    printf("---");
    for (i = 0; i < MAX; ++i)
        printf("---");
    printf("\n");

    for (i = 0; i < MAX; ++i)
        printf(" %d ", i);
    printf("\n");

    /* vertical */
    printf("\n");
    for (i = MAX-1; i >= 0; --i) {
        if (i > 9)
            printf("%d | ", i);
        else
            printf(" %d |", i);
        for (j = 0; j < wlen[i]; ++j)
            printf("x");
        printf("\n");
    }

    return 0;
}
