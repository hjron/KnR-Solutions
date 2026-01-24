#include <stdio.h>

int main(int argc, char *argv[]) {
    int c, blanks, tabs, nl;

    nl = blanks = tabs = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++tabs;
        else if (c == ' ')
            ++blanks;
    printf("number of lines: %d", nl);
    printf(" number of tabs: %d", tabs);
    printf(" number of blanks: %d\n", blanks);
    return 0;
}
