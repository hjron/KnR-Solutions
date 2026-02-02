#include <stdio.h>

void escape(const char s[], char t[]);
void unescape(const char s[], char t[]);

int main(int argc, char *argv[]) {
    const char s[] = "this is a		test";
    char t[50];
    char u[50];

    escape(s, t);
    printf("%s\n", t);

    unescape(t, u);
    printf("%s\n", u);

    return 0;
}

/* escape: convert \n and \t into visible characters */
void escape(const char s[], char t[]) {
    int i, j, c;

    i = j = 0;
    while ((c = s[i++]) != '\0') {
        switch (c) {
            case '\t':
                t[j++] = '\\', t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\', t[j++] = 'n';
                break;
            default:
                t[j++] = c;
                break;
        }
    }
    t[j] = '\0';
}

/* unescape: convert literal '\t', '\n' to real characters */
void unescape(const char s[], char t[]) {
    int i, j, c;

    i = j = 0;
    while ((c = s[i++]) != '\0') {
        if (c == '\\') {
            switch(s[++i]) {
                case 't':
                    t[j++] = '\t';
                    break;
                case 'n':
                    t[j++] = '\n';
                    break;
                default:
                    break;
            }
        } else {
            t[j++] = c;
        }
        t[j] = '\0';
    }

}
