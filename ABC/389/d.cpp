#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ll r;
    cin >> r;

    auto inside = [&](ll x, ll y)
    {
        x = x * 2 + 1;
        y = y * 2 + 1;
        return x * x + y * y <= r * r * 4;
    };

    ll ans = 0;
    ll x = 0;
    for (ll y = r; y >= 0; y--)
    {
        while (inside(x + 1, y))
            x++;
        ans += x;
    }
    ans *= 4;
    ans++;
    cout << ans << endl;
    return 0;
}