#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(int argc, char *argv[]) {
    int x, base;
    char xs [25];

    x = 255;
    base = 8;
    itob(x, xs, base);
    printf("the integer %d is now the base-%d string %s\n", x, base, xs);

    return 0;
}

/* reverse: reverse a string in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;    /* can be 3 stmts, with ; for , */
}

/* itob: convert n to a base b characters in s */
void itob(int n, char s[], int b) {
    int i, x, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;
    i = 0;
    do {                    /* generate digits in reverse order */
        x = n % b;
        s[i++] = (x <= 9) ? x + '0' : x + 'a' - 10;
    } while ((n /= b) > 0);   /* delete it */
    if (sign < 0) 
        s[i++] = '-';
    
    switch (b) {
        case 8:
            s[i++] = '0';
            break;
        case 16:
            s[i++] = '0', s[i++] = 'x';
            break;
        default:
            break;
    }

    s[i] = '\0';
    reverse(s);
}
