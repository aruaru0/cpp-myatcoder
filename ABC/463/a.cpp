#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

int main()
{
    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);

    x /= g;
    y /= g;
    if (x == 16 && y == 9)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}