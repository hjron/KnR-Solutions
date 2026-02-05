#include <ctype.h>

/* atof: convert string s, even with scientific notation, to double */
/* compile, test with rcalc and gline */
double atof(char s[]) {
    double val, power;
    int i, sign, exp;

    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    /* deal with scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? 0 : 1; /* bool, not multiplicative */
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');

        for (power = 1; exp > 0; exp--)
            power *= 10;
        if (sign)
            val *= power;
        else
            val /= power;
    }
    return val;
}
