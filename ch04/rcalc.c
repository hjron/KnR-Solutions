#include <stdio.h>

#define MAXLINE 1000

/* rudimentary calculator: gcc rcalc.c gline.c atof.c (or ex4_2.c) */
int main(int argc, char *argv[]) {
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += a2f(line));

    return 0;
}
