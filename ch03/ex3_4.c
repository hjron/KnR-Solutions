#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main(int argc, char *argv[]) {
    int x;
    char xs [25];

    x = -2147483648;    /* the largest negative int */
    itoa(x, xs);
    printf("the integer %d is now the string %s\n", x, xs);

    return 0;
}

/* reverse: reverse a string in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;    /* can be 3 stmts, with ; for , */
}

/* itoa: convert n to characters in s, updated to handle largest negative num */
void itoa(int n, char s[]) {
    int i, x, sign;

    sign = n;               /* record sign */
    i = 0;
    do {                    /* generate digits in reverse order */
        x = n % 10;
        if (x < 0)
            x *= -1;
        s[i++] = x + '0';       /* get next digit */
    } while ((n /= 10) != 0);   /* delete it */
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
