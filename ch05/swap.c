#include <stdio.h>

void swap(int *px, int *py);

int main(int argc, char *argv[]) {
    int x, y;

    x = 10;
    y = 3;
    printf("before x, y: %d, %d\n", x, y);
    swap(&x, &y);
    printf("after x, y: %d, %d\n", x, y);

    return 0;
}

/* swap: swap the values using pointers */
void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
