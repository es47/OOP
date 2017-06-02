/* 林佳萱  404410062   資工二*/

//Driver program for the function showCalendar.
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

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
    char ans;
    do
    {
        cout << "Enter year and month.\n";
        cin >> year >> month;
        getFirstDayOfMonth(year, month, first_weekday, number_of_month);
        if (first_weekday == 0)
            first_weekday = 7;
        cout << "Suppose the first weekday is " << first_weekday << endl;
        cout << "And the number of month is " << number_of_month << endl;
        if (first_weekday == 7)
            first_weekday = 0;
        cout << "The calendar of " << year << " " << month << "is:\n";
        showCalendar(year, month, first_weekday, number_of_month);
        cout << "Test again? (y/n)\n";
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

int getFirstDayOfMonth(int year, int month, int& weekday_st, int& num_month)
{
    weekday_st = rand() % 7;
    if (month == 2)
        num_month = rand() % 2 + 28;
    else
        num_month = rand() % 2 + 30;
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
