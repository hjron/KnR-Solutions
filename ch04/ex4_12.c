#include <stdio.h>

void itoa(int n);

int main(int argc, char *argv[]) {
    int n = -123456;
    printf("the int %d converts to string: \"", n);
    itoa(n);
    printf("\"\n");
    return 0;
}

/* itoa: convert integer to string using recursion
 * compare to ch03, no need to call reverse */
void itoa(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        itoa(n / 10);

    putchar(n % 10 + '0');
}
