#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main(int argc, char *argv[]) {
    char s[] = "this string has lots of whitespace  	 ";
    printf("length before trim: %lu\n", strlen(s));
    printf("length after trim: %d\n", trim(s));
    
    return 0;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}
