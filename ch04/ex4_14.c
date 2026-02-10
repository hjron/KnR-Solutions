#include <stdio.h>

#define swap(t, x, y) t tmp; tmp = x, x = y, y = tmp;

int main(int argc, char *argv[]) {
    int x = 5;
    int y = 10;

    printf("x is %d, y is %d\n", x, y);
    swap(int, x, y);
    printf("after swap x is %d, y is %d\n", x, y);
    return 0;
}
