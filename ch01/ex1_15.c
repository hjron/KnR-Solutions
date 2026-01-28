#include <stdio.h>

/* use a function to print Fahrenheit to 
 * Celsius table for fahr = 0, 20, ..., 300 */

#define LOWER 0         /* lower limit for table */
#define UPPER 300       /* upper limit for table */
#define STEP 20         /* step size */

float f_to_c(int f);

int main(int argc, char *argv[]) {
    printf("fahr  celsius\n-----------\n");
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, f_to_c(fahr));
    return 0;
}

float f_to_c(int f) {
    return (5.0 / 9.0) * (f - 32);
}
