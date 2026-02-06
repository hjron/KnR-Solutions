#include <stdio.h>

int atoi(char s[]);

int main(int argc, char *argv[]) {
    char s[] = "123456";
    printf("the string \"%s\" is converted to %d integer\n", s, atoi(s));
    return 0;
}

/* atoi: convert string s to integer using atof */
int atoi(char s[]) {
    double a2f(char s[]);
    return (int) a2f(s);
}
