#include <stdio.h>

void strn_cpy(char *s, char *t, int n);
void strn_cat(char *s, char *t, int n);
int strn_cmp(char *s, char *t, int n);

int main(int argc, char *argv[]) {
    char *t = "hallelujah!";
    char s[20];
    strn_cpy(s, t, 10);
    printf("%s\n", s);

    char a[20] = "hello ";
    char *b = "ron";
    strn_cat(a, b, 3);
    printf("%s\n", a);
    
    char *m = "help";
    char *n = "hello";
    printf("first 4 chars of %s compared to %s: %d\n", m, n, strn_cmp(m, n, 4));

    return 0;
}

/* strncpy: copies at most n characters of t to s, pad remaining space with \0 */
void strn_cpy(char *s, char *t, int n) {
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}

/* strncat: concatenate at most n characters of t to s */
void strn_cat(char *s, char *t, int n) {
    char *p = s;
    int i = 0;

    while (*p++ != '\0')
        i++;
    strn_cpy(s + i, t, n);
}

/* strncmp: compare at most n characters of s to t, return <0 if s<t, 
 * 0 if s==t, >0 if s>t */
int strn_cmp(char *s, char *t, int n) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
