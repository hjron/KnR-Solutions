#include <stdio.h>

int stlen(char *s);
int pstlen(char *s);

int main(int argc, char *argv[]) {
     char s[] = "hello there!";
    printf("length of string \"%s\" is %d\n", s, pstlen(s));

    return 0;
}

/* stlen: return length of string s */
int stlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;

    return n;
}

int pstlen(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}
