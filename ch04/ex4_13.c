#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_helper(char s[], int start, int end);

int main(int argc, char *argv[]) {
    char s[] = "hogwarts";
    printf("s is %s ", s);
    reverse(s);
    printf("and reversed it is %s\n", s);
    return 0;
}

/* reverse: call recursive function on s */
void reverse(char s[]) {
    reverse_helper(s, 0, strlen(s));
}

/* reverse_helper: reverse s in place recursively 
 * compare to reverse in ch03 (itoa) */
void reverse_helper(char s[], int i, int len) {
    int c, j;
    j = len - (i + 1);
    
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverse_helper(s, i+1, len);
    }
}
