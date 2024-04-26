#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 2014 || n == 2017)
    {
        cout << -1 << endl;
    }
    else if (n <= 2016)
    {
        cout << n - 2014 << endl;
    }
    else
    {
        cout << n - 2015 << endl;
    }

    return 0;
}