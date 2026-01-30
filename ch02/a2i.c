#include <stdio.h>

int a2i(const char s[]);
int lower(int c);

int main(int argc, char *argv[]) {
    const char s[] = "456789";
    char uc[] = "HELLO";
    int i;

    printf("converted string \"%s\" is %d integer\n", s, a2i(s));

    i = 0;
    printf("lower case \"%s\" is: ", uc);
    while (uc[i] != '\0')
        printf("%c", lower(uc[i++]));
    printf("\n");

    return 0;
}

/* a2i: convert s to integer */
int a2i(const char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
