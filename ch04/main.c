#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/* rpn calc */
int main(int argc, char *argv[]) {
    int type, rhs;
    double op2;
    char s[MAXOP];

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
                rhs = (int) pop();
                if (op2 != 0)
                    push((int) pop() % rhs);
                else
                    printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
