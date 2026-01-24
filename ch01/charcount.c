#include <stdio.h>

/* count characters in input */

int main(int argc, char *argv[]) {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("number of characters: %.0f\n", nc);
    return 0;
}
