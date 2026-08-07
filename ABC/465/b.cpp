#include <iostream>

using namespace std;

int main()
{
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    int tot = 0;

    for (int i = a; i < b; i++)
    {
        if (l <= i && i < r)
        {
            tot += x;
        }
        else
        {
            tot += y;
        }
    }

    cout << tot << endl;
}