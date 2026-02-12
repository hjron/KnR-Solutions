#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
void ungetch(int c);
int getint(int *pn);

char buf[SIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int main() {
    int n, array[SIZE], i;

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= SIZE)
        printf("error: ungetch not enough space\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, x, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                 /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        x = c;
        while (isspace(c = getchar()))
            ;
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(x);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
