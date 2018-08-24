/* 林佳萱  404410062   資工二*/

//Driver program for the function getFirstDayOfMonth.
#include <iostream>

using namespace std;

int getFirstDayOfMonth(int year, int month, int& weekday_st, int& num_month);
//Precondition: weekday_st is the first day of the month.
//num_month is the number of the month.
//Postcondition: find out the first weekday of the input month
//and the number of the input month.

int main()
{
    int year, month, first_weekday, number_of_month;
    char ans;
    do
    {
        cout << "Enter year and month.\n";
        cin >> year >> month;
        getFirstDayOfMonth(year, month, first_weekday, number_of_month);
        cout << "The first day of " << year << " " << month << "is "
                << first_weekday << endl;
        cout << "The number of " << year << " " << month << "is "
                << number_of_month << endl;
        cout << "Test again? (y/n)\n";
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');
    return 0;
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
