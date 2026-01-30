#include <stdio.h>

int h2i(const char s[]);

int main(int argc, char *argv[]) {
    const char h[] = "0xFf";
    printf("the hex string \"%s\" converts to %d decimal\n", h, h2i(h));

    return 0;
}

/* h2i: convert a hex digit string to the equivalent integer */
int h2i(const char s[]) {
    int startidx, i, h, c;

    startidx = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        startidx = 2;

    h = 0;
    for (i = startidx; s[i] != '\0'; ++i) {
        c = s[i];
        if (c >= 'A' && c <= 'F')
            c -= '7';   /* converts to [10, 15] */
        else if (c >= 'a' && c <= 'f')
            c -= 'W';   /* converts to [10, 15] */
        else
            c -= '0';   /* converts to decimal equivalent */
        h = 16 * h + c;
    }
    return h;
}
