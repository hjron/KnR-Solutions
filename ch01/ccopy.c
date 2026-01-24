#include <stdio.h>
/* read a character
 * while character is not EOF
 *  output the character just read
 *  read another character */

int main(int argc, char *argv[]) {
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);

    return 0;
}
