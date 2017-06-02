/* 林佳萱  404410062   資工二*/

//Driver program for the function inputYrMn.
#include <iostream>

using namespace std;

bool inputYrMn(int& yr, int& mn);
//Precondition: yr is year. mn is month.
//Postcondition: check the correction of the input year and month.

int main()
{
    int year, month;
    char ans;
    do
    {
        cout << "Enter year and month.\n";
        cin >> year >> month;
        cout << "your enter is ";
        if (inputYrMn(year, month) == true)
            cout << "correct.\n";
        else
            cout << "wrong.\n";
        cout << "Test again? (y/n)\n";
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');
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
