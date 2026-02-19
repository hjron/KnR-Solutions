#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000     /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n);
void afree(char *p);

void strcopy1(char *s, char *t);
void strcopy2(char *s, char *t);
void strcopy3(char *s, char *t);
void strcopy4(char *s, char *t);

int main(int argc, char *argv[]) {
    char *t = "hello there";
    char *s = alloc(strlen(t) + 1);

    /* strcopy1(s, t); */
    strcopy4(s, t);
    printf("t: %s, s: %s\n", t, s);

    afree(s);

    return 0;
}

/*strcopy1: copy t to s; array subscript version */
void strcopy1(char *s, char *t) {
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

/* strcopy2: copy t to s; pointer version 1 */
void strcopy2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcopy3: copy t to s; pointer version 2 */
void strcopy3(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

/* strcopy4: copy t to s; pointer version 3 */
void strcopy4(char *s, char *t) {
    while ((*s++ = *t++))
        ;
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
