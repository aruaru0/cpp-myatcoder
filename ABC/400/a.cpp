#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int b = 400 / a;

    if (a * b == 400)
    {
        cout << b << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}