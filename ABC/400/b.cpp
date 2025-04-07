#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    ll x = 0;
    ll pow = 1;

    const int inf = 1e9;
    for (int i = 0; i <= m; i++)
    {
        x += pow;
        if (x > inf)
        {
            cout << "inf" << endl;
            return 0;
        }
        if (pow / n > inf)
        {
            cout << "inf" << endl;
            return 0;
        }
        pow *= n;
    }
    cout << x << endl;
}