/*  404410062   資工二*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool inputYrMn(int& yr, int& mn);
//Precondition: yr is year. mn is month.
//Postcondition: check the correction of the input year and month.

int getFirstDayOfMonth(int year, int month, int& weekday_st, int& num_month);
//Precondition: weekday_st is the first day of the month.
//num_month is the number of the month.
//Postcondition: find out the first weekday of the input month
//and the number of the input month.

void showCalendar(int year, int month, int first_weekday, int number_of_month);
//Postcondition: show out the month's calendar.

int main()
{
    int year, month, first_weekday, number_of_month;
    bool check_yr_mn;
    while(1)
    {
        cin >> year >> month;
        check_yr_mn = inputYrMn(year, month);
        if (check_yr_mn == false)
        {
            cout << "enter Year or Month is wrong!\n";
            continue;
        }
        getFirstDayOfMonth(year, month, first_weekday, number_of_month);
        showCalendar(year, month, first_weekday, number_of_month);
    }
    return 0;
}

bool inputYrMn(int& yr, int& mn)
{
    if (yr > 2099 || yr < 1901)
        return false;
    else if (mn > 12 || mn < 1)
        return false;
    else
        return true;
}

int getFirstDayOfMonth(int year, int month, int& weekday_st, int& num_month)
{
    int month_days;
    bool leap_year;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        num_month = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        num_month = 30;
        break;
    case 2:
        if ((year % 400 == 0) || (year % 4 == 0 && (year % 100 != 0)))  //check leap.
        {
            num_month = 29;
            leap_year = true;
        }
        else
        {
            num_month = 28;
            leap_year = false;
        }
        break;
    }
    //count the first day.
    if (month == 1 || month == 2)                       // 1st and 2nd month is defined
    {
        month += 12;                                    //as 13th and 14th month.
        month_days = (month + 1) * 26 / 10 % 7 - 1;
        if (leap_year == true)                          //leap year needs to minus 1
            month_days = (month_days + 6) % 7;
    }
    else
        month_days = (month + 1) * 26 / 10 % 7;
    weekday_st = (year + year / 4 + year / 400 - year / 100 + month_days) % 7;
    return 0;
}

void showCalendar(int year, int month, int first_weekday, int number_of_month)
{
    int i, count_day;
    char month_name[12][10] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    cout << "-----------------------------------\n";
    cout << setw(16) << year << "  " << month_name[month - 1] << endl;
    cout << "-----------------------------------\n";
    cout << setw(4) << "SUN" << setw(5) << "MON" << setw(5) << "TUE" << setw(5) << "WED"
         << setw(5) << "THU" << setw(5) << "FRI" << setw(5) << "SAT" << endl;
    cout << setw(first_weekday * 5 + 3) << "1";
    count_day = first_weekday + 1;
    for (i = 2;  i <= number_of_month; i++)
    {
        if (count_day == 7)
        {
            cout << endl;
            count_day = 0;
        }
        if (count_day == 0)
            cout << setw(3) << i;
        else
            cout << setw(5) << i;
        count_day++;
    }
    if (count_day != 0)
        cout << endl;
    cout << "-----------------------------------\n\n";
}
