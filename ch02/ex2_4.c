#include <stdio.h>

enum boolean { FALSE, TRUE };

void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[]) {
    char s1[] = "ironic";
    char s2[] = "ic";

    printf("before squeeze: %s\n", s1);
    squeeze(s1, s2);
    printf("after squeeze: %s\n", s1);
    return 0;
}

/* squeeze: delete each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[]) {
    enum boolean valid;
    int i, j, k;

    k = 0;                                  /* remember position for new s1 */
    for (i = 0; s1[i] != '\0'; ++i) {       /* take one char from s1 */
        valid = TRUE;
        j = 0;
        while (s2[j] != '\0') {             /* compare to each char in s2 */
            if (valid && s1[i] == s2[j])    /* but only if no match before */
                valid = FALSE;
            ++j;
        }
        if (valid) {                        /* copy if still valid */
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
