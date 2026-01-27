#include <stdio.h>

int main(int argc, char *argv[]) {
    int c;

    c = getchar() != EOF;
    printf("c != EOF: %d\n", c);

    c = getchar() == EOF;
    printf("c == EOF: %d\n", c);

    return 0;
}
