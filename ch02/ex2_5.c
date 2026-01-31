#include <stdio.h>

int any(const char s1[], const char s2[]);

int main(int argc, char *argv[]) {
    const char s1[] = "function";
    const char s2[] = "math";

    printf("char found at index %d\n", any(s1, s2));

    const char s3[] = "parse";
    printf("char found at index %d\n", any(s1, s3));

    return 0;
}

/* any: return the first location in s1 where any character from s2 occurs */
int any(const char s1[], const char s2[]) {
    int i, j;

    for (i = 0; s2[i] != '\0'; ++i) {
        j = 0;
        while (s1[j] != '\0')
            if (s2[i] == s1[j++])
                return --j;
    }
    return -1;
}
