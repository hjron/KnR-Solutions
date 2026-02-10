#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand, including negative */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    if (!isdigit(c) && c != '.' && c != '-')
        return c;       /* command */

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {     /* negative int */
            s[++i] = c;
        } else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) 
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    printf("s: %s\n", s);
    return NUMBER;
}
