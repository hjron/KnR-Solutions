#include <stdio.h>
#define MAXLINE 30    /* max input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(int argc, char *argv[]) {
    int len;                /* current line length */
    int max;                /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)            /* there was a line */
        printf("%d, %s", max, longest);

    return 0;
}

/* get_line: read a line into s, return length 
 * modified to return length > lim and get lim chars into s */
int get_line(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 2)
            s[j++] = c;
    if (c == '\n') {
        s[j++] = c;
        ++i;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
