#include <iostream>

using namespace std;

bool isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int year;
    cin >> year;
    if (isLeapYear(year))
    {
        cout << 366 << endl;
    }
    else
    {
        cout << 365 << endl;
    }
}