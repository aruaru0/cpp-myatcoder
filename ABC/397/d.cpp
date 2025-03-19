#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    for (ll d = 1; d * d * d < n; d++)
    {
        ll c = n - d * d * d;
        if (c % (3 * d))
            continue;
        c /= 3 * d;
        ll y = (sqrt(d * d + 4 * c) - d) / 2;
        if (y * y + d * y - c == 0)
        {
            cout << y + d << ' ' << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}