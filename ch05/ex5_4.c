#include <stdio.h>

int strend(char *s, char *t);

int main(int argc, char *argv[]) {
    char *s = "buildings";
    char *t = "ding";

    printf("should be zero: %d\n", strend(s, t));
    return 0;
}

/* strend: return 1 if t occurs at the end of s, else 0 */
int strend(char *s, char *t) {
    char *p = t;

    while (*p++ != '\0')
        s++;

    for ( ; *s == *t; s++, t++)
        if (*s == '\0' && *t == '\0')
            return 1;
    return 0;
}
