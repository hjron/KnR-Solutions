#include <stdio.h>
#include "calc.h"

#define MAXVAL 100  /* max depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: empty stack\n");
        return 0.0;
    }
}

/* peek: return top value from stack */
double peek(void) {
    if (sp > 0) {
        return val[sp-1];
    } else {
        printf("error: empty stack\n");
        return 0.0;
    }
}

/* copy: duplicate top element */
void copy(void) {
    if (sp > 0 && sp < MAXVAL) {
        val[sp] = val[sp-1];
        sp++;
    } else {
        printf("error: empty stack\n");
    }
}

/* swap: swap top two elements in the stack */
void swap(void) {
    if (sp > 1) {
        double tmp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = tmp;
    } else {
        printf("error: too few elements in stack\n");
    }
}

/* clear: 'erase' the stack */
void clear(void) {
    sp = 0;
}
