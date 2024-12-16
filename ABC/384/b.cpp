#include <iostream>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    for (int i = 0; i < n; i++)
    {
        int d, x;
        cin >> d >> x;
        if (d == 1)
        {
            if (1600 <= r && r <= 2799)
                r += x;
        }
        else if (1200 <= r && r <= 2399)
            r += x;
    }
    cout << r << endl;
}