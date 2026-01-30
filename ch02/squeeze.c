#include <stdio.h>

void squeeze(char s[], int c);
void str_cat(char s[], char t[]);

int main(int argc, char *argv[]) {
    char s[] = "standard";
    char a[50] = "hello ";
    char b[] = "ron!";
    int c = 'd';

    printf("\"%s\" squeezed of '%c' is ", s, c);
    squeeze(s, c);
    printf("\"%s\"\n", s);

    str_cat(a, b);
    printf("a + b is: %s\n", a);
    return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
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
