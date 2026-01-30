#include <stdio.h>

unsigned long int next = 1;

int myrand(void);
void mysrand(unsigned int seed);

int main(int argc, char *argv[]) {
    int i;
    mysrand(425); 
    for (i = 0; i < 10; ++i)
        printf("%d\n", myrand());
    return 0;
}

/* myrand: return pseudo-random integer on 0..32767 */
int myrand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* mysrand: set seed for myrand */
void mysrand(unsigned int seed) {
    next = seed;
}
