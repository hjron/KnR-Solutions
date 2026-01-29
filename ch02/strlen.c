#include <stdio.h>

int str_len(const char s[]);

int main(int argc, char *argv[]) {
    const char s[] = "hi ron!";
    printf("the length of \"%s\" is %d\n", s, str_len(s));
    return 0;
}

/* strlen: return length of s */
int str_len(const char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}
