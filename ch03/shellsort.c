#include <stdio.h>
#include <stdlib.h> /* for rand() */

#define SIZE 15
#define LIMIT 100

void shellsort(int v[], int n);

int main(int argc, char *argv[]) {
    int i, v[SIZE];

    for (i = 0; i < SIZE; ++i)
        v[i] = rand() % (LIMIT + 1);

    printf("before sort: ");
    for (i = 0; i < SIZE; ++i)
        printf("%d ", v[i]);

    shellsort(v, SIZE);
    
    printf("\nafter sort: ");
    for (i = 0; i < SIZE; ++i)
        printf("%d ", v[i]);

    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; ++i)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
