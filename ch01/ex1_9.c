#include <stdio.h>
/* replace multiple spaces with one space */

int main(int argc, char *argv[]) {
    int c, count;

    count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++count;
        else
            count = 0;

        if (count < 2)
            putchar(c);
    }

    return 0;
}
