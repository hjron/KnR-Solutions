#include <stdio.h>

/* add error checking for the two functions */

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char *argv[]) {
    int year, month, day;
    int m, d, doy;

    year = 1988;
    day = 60;
    month_day(year, day, &m, &d);
    if (m && d)
        printf("day %d in year %d is day %d of month %d\n",
                day, year, d, m);
    else
        printf("error: invalid year (%d) or day (%d)\n", year, day);

    month = 5;
    day = 12;
    doy = day_of_year(year, month, day);
    if (doy)
        printf("day %d of month %d of year %d is day %d of the year\n",
                day, month, year, doy);
    else
        printf("error: invalid year (%d) or month (%d) or day (%d)\n",
                year, month, day);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    if (year > 0 && month > 0 && month < 13 && day > 0 && day < 32) {
        int i, leap;

        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
    } else {
        return daytab[0][0];
    }
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year > 0 && yearday > 0 && yearday < 366) {
        int i, leap;

        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    } else {
        *pmonth = daytab[0][0];
        *pday = daytab[0][0];
    }
}
