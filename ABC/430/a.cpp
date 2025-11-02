#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    if (c >= a && d < b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}