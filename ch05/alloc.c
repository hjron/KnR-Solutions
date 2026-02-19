#include <stdio.h>

#define ALLOCSIZE 10000     /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n);
void afree(char *p);

int main(int argc, char *argv[]) {
    /* the string is hello, need 5 for characters + 1 for '\0' */
    char *pc = alloc(6);
    pc = "hello";
    printf("the string is: %s\n", pc);
    afree(pc);
    return 0;
}

/* alloc: returns a pointer to contiguous memory */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else                  /* not enough room */
        return 0;
}

/* afree: releases memory allocated by alloc */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
