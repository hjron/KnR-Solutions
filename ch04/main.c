#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

enum bool { no, yes };

/* rpn calc */
/* operations that manipulate the stack without a math operation
 * e.g., peek and swap, require extra logic so new line doesn't pop */
int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    enum bool must_pop; /* keep stack intact after pressing enter */

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: zero division\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero division\n");
                break;
            case '\n':
                if (must_pop)
                    printf("\t%.8g\n", pop());
                must_pop = yes;
                break;
            case 'p': /* peek */
                printf("\t%.8g\n", peek());
                must_pop = no;
                break;
            case 'd': /* duplicate */
                copy();
                must_pop = no;
                break;
            case 's': /* swap top 2 elements */
                swap();
                must_pop = no;
                break;
            case 'c': /* erase the stack */
                clear();
                must_pop = no;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
