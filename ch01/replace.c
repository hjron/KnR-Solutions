#include <stdio.h>
/* replace tabs with "\t", backspaces with "\b", a single backslash \ with two */

int main(int argc, char *argv[]) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}
