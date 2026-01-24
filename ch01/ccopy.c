#include <stdio.h>
/* read a character
 * while character is not EOF
 *  output the character just read
 *  read another character */

int main(int argc, char *argv[]) {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}
