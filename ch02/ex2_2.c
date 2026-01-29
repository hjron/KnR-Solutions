#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, c, lim;

    lim = 1000;
    /* the for loop stops when it hits the first '\n'
     * and prints 0 1 ... 17 when the program is run with itself */
    /*
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        printf("%d ", i);
    }
    */

    /* the while loop prints 0 1 ... 17 when the program is run with itself */
    i = 0;
    while (i < lim - 1) {
        c = getchar();
        if (c == '\n') {
            i = lim -1;
        }
        else if (c == EOF) {
            i = lim - 1;
        } else {
            printf("%d ", i);
        }
        ++i;
    }
    return 0;
}
