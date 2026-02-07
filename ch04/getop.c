#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand, including negative */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;       /* not a number */
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {     /* negative int */
            s[++i] = c;
        } else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }

    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))

    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
