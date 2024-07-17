#include <iostream>

using namespace std;

int calc(int x0, int y0, int x1, int y1)
{
    return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
}

int main()
{
    int x0, y0, x1, y1, x2, y2;

    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    int d01 = calc(x0, y0, x1, y1);
    int d02 = calc(x0, y0, x2, y2);
    int d12 = calc(x1, y1, x2, y2);
    if (d01 + d02 == d12 || d01 + d12 == d02 || d02 + d12 == d01)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}