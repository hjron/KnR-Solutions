#include <stdio.h>
#include <limits.h>

/* ranges of various data types, tricky format specifiers! */
int main(int argc, char *argv[]) {
    printf("char min: %d, max: %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char min: %d, max: %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);

    printf("unsigned short int max: %u\n", USHRT_MAX);
    printf("short signed int min: %d, max: %d\n", SHRT_MIN, SHRT_MAX);

    printf("unsigned int max: %u\n", UINT_MAX);
    printf("signed int min: %d, max: %d\n", INT_MIN, INT_MAX);

    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("signed long min: %ld, max: %ld\n", LONG_MIN, LONG_MAX);

    return 0;
}
