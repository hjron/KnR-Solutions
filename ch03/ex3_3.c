#include <stdio.h>
#include <string.h>

/* elegant but NOT my solution */

void expand(char s1[], char s2[]);

int main(int argc, char *argv[]) {
    char s1[] = "a-zA-Z";
    char s2[1000];

    expand(s1, s2);

    printf("%s\n", s2);
    return 0;
}

/* expand: expand shorthand notation like a-z into abc...xyz */
void expand(char s1[], char s2[]) {
    char c;
    int i, j;
    
    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] >= c) { /* skip range delimiter '-' */
            i++;
            while (c < s1[i])               /* fill in the range */
                s2[j++] = c++;
        } else                              /* add last char in the range */
            s2[j++] = c;
    }
    s2[j] = '\0';                           /* null terminator */
}
