#include <stdio.h>

#define SIZE 10

int binsearch(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

int main(int argc, char *argv[]) {
    int i, needle;

    int haystack[SIZE];

    needle = 4;
    for (i = 0; i < SIZE; ++i)
        haystack[i] = i;

    printf("match found at index %d\n", binsearch(needle, haystack, SIZE));
    printf("match found at index %d\n", binsearch1(needle, haystack, SIZE));
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
