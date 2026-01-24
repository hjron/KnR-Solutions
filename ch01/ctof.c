#include <stdio.h>

/* celsius to fahrenheit conversion table */

#define LOWER 0
#define UPPER 100
#define STEP 5

int main(int argc, char *argv[]) {

    for (int celsius = LOWER; celsius <= UPPER; celsius += STEP)
        printf("%3d\t%3.0f\n", celsius, celsius * 9.0 / 5.0 + 32);

    return 0;
}
