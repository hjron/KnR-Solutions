#include <stdio.h>
#include <time.h>

/* timing functionality based on stackoverflow:
 * /questions/459691/what-is-the-best-timing-method-in-c */

#define SIZE 10
#define ITERATIONS 10000000

int binsearch(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

int main(int argc, char *argv[]) {
    int i, needle, haystack[SIZE];
    clock_t start, diff;

    needle = 9;
    for (i = 0; i < SIZE; ++i)
        haystack[i] = i;

    start = clock();
    for (i = 0; i < ITERATIONS; ++i)
        binsearch(needle, haystack, SIZE);
    diff = clock() - start;
    printf("msec for %d iterations of binsearch: %lu\n", 
            ITERATIONS, diff * 1000 / CLOCKS_PER_SEC);
    
    start = clock();
    for (i = 0; i < ITERATIONS; ++i)
        binsearch1(needle, haystack, SIZE);
    diff = clock() - start;
    printf("msec for %d iterations of binsearch1: %lu\n", 
            ITERATIONS, diff * 1000 / CLOCKS_PER_SEC);

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int lo, hi, mid;
    
    lo = 0;
    hi = n - 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (x < v[mid])
            hi = mid - 1;
        else if (x > v[mid])
            lo = mid + 1;
        else    /* match! */
            return mid;
    }
    return -1;  /* no match */
}

/* binsearch1: find x in v[] with one test in the loop */
int binsearch1(int x, int v[], int n) {
    int lo, hi, mid;
    
    lo = 0;
    hi = n - 1;
    mid = (lo + hi) / 2;
    while (lo <= hi && v[mid] != x) {
        if (x < v[mid])
            hi = mid - 1;
        else 
            lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    return (v[mid] == x) ? mid : -1;  
}
