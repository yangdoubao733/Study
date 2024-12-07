#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

// Function to determine if it's a leap year
bool isLeapYear(struct date *d)

{

    bool leapYearFlag = false;
    if ((d->year % 4 == 0 && d->year % 100 != 0) || d->year % 400 == 0)
    {
        leapYearFlag = true;
    }
    return leapYearFlag;
}

// Function to find the number of days in a month
int numberOfDays(struct date *d)

{

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(d) == true && d->month == 2)
    {
        return 29;
    }
    else
    {
        return days[d->month - 1];
    }
}

struct date dateUpdate(struct date *today)

{

    struct date tomorrow;

    if (today->day != numberOfDays(today))
    {
        tomorrow.day = today->day + 1;
        tomorrow.month = today->month;
        tomorrow.year = today->year;
    }
    else if (today->month != 12)
    {
        tomorrow.day = 1;
        tomorrow.month = today->month + 1;
        tomorrow.year = today->year;
    }
    else
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today->year + 1;
    }

    return tomorrow;
}

int main()

{

    struct date today, *thisDay, nextDay;
    scanf("%d %d %d", &today.month, &today.day, &today.year);
    thisDay = &today;
    nextDay = dateUpdate(thisDay);
    printf("Tomorrow's date is %d/%d/%d.", nextDay.month, nextDay.day, nextDay.year);
}
