#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be stored */
#define MAXLEN 1000         /* max length of any input line */

char *lineptr[MAXLINES];            /* pointers to text lines */

int readlines(char *lineptr[], char mainlines[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int get_line(char *line, int lim);
void swap(char *v[], int i, int j);

int main(int argc, char *argv[]) {
    int nlines;         /* number of input lines read */
    char mainlines[MAXLINES*MAXLEN];

    if ((nlines = readlines(lineptr, mainlines, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char mainlines[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *endofline = mainlines + MAXLINES * MAXLEN;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || mainlines + len >= endofline)
            return -1;
        else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(mainlines, line);
            lineptr[nlines++] = mainlines;
            mainlines += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
    
}

/* getline: read a line into s, return length */
int get_line(char *s, int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void swap(char *v[], int i, int j) {
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right)  /* do nothing if v has less than 2 elements */
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
