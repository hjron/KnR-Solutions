#ifndef CALC_H
#define CALC_H

/* calc.h: function declarations for rpn calculator */

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

double a2f(char []);
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

#endif
