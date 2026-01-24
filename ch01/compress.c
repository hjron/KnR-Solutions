#include <stdio.h>
/* read a character
 * while character is not EOF
 *  output the character just read
 *  read another character */

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
