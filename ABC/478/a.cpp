#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int d = m / n, r = m % n;
    for (int i = 0; i < n; i++)
    {
        if (i < r)
        {
            cout << d + 1 << endl;
        }
        else
        {
            cout << d << endl;
        }
    }
}