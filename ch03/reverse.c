#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(int argc, char *argv[]) {
    char s[] = "ron hagen";
    printf("before reverse: %s\n", s);
    reverse(s);
    printf("after reverse: %s\n", s);
    return 0;
}

/* reverse: reverse a string in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;    /* can be 3 stmts, with ; for , */
}
