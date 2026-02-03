#include <stdio.h>

void itoa(int n, char s[]);

int main(int argc, char *argv[]) {
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
