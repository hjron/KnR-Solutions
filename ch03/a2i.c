#include <stdio.h>
#include <ctype.h>

/* revised version, compare to the file of same name ini ch02 */

int a2i(const char s[]);

int main(int argc, char *argv[]) {
    const char s[] = "456789";
    int i;

    printf("converted string \"%s\" is %d integer\n", s, a2i(s));

    return 0;
}

/* a2i: convert s to integer; version 2 */
int a2i(const char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')     /* skip sign */
        ++i;
    for (n = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
