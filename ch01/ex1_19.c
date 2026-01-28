#include <stdio.h>
#define MAXLINE 1000    /* max input line length */

void reverse(char s[], int len);
int get_line(char line[], int maxline);

/* reverse input lines using a function */
int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

/* reverse: reverse a string in place, modeled after swap */
void reverse(char s[], int len) {
    int i, j, c;

    /* len - 1: don't mess with the '\0' */
    for (i = 0, j = len - 1; i < len / 2; --j, ++i) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
