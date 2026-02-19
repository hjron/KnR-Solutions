#include <stdio.h>

void str_cat(char s[], char t[]);
void strcatp(char *s, char *t);

int main(int argc, char *argv[]) {
    char a[50] = "hello ";
    char *b = "ron!";

    strcatp(a, b);
    printf("a + b is: %s\n", a);

    return 0;
}

/* str_cat: concatenate t to end of s; s must be big enough */
void str_cat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0')    /* find the end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0')   /* copy t */
        ;
}

/* strcatp: pointer version */
void strcatp(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}
