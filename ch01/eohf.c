#include <stdio.h>

int main(int argc, char *argv[]) {
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);

    /* c should be EOF when while loop exits */
    printf("EOF: %d\n", c);

    return 0;
}
