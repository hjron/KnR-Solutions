#include <stdio.h>

int strcomp(char *s, char *t);
int strcomp1(char *s, char *t);

int main(int argc, char *argv[]) {
    char *s = "hello";
    char *t = "cello";

    printf("s compared to t: %d\n", strcomp1(s, t));
    return 0;
}

/* strcomp: returns <0 if s<t, 0 if s==t, >0 if s>t */
int strcomp(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* strcomp1: pointer version */
int strcomp1(char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
