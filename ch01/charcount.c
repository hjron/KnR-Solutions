#include <stdio.h>

/* count characters in input */

int main(int argc, char *argv[]) {
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("number of characters: %ld\n", nc);
    return 0;
}
