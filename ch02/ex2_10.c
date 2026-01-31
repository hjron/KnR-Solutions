#include <stdio.h>

int lower(int c);

int main(int argc, char *argv[]) {
    char uc[] = "HELLO";
    int i;

    i = 0;
    printf("lower case \"%s\" is: ", uc);
    while (uc[i] != '\0')
        printf("%c", lower(uc[i++]));
    printf("\n");

    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
