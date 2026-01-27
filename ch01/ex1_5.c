#include <stdio.h>

/* print Fahrenheit to Celsius table for
 * fahr = 300, 280, ..., 0 */

#define LOWER 0         /* lower limit for table */
#define UPPER 300       /* upper limit for table */
#define STEP 20         /* step size */

int main(int argc, char *argv[]) {
    printf("fahr  celsius\n-----------\n");
    for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    return 0;
}
