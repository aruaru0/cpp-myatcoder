#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll f(ll a, ll b, ll x, ll y)
{
    x = abs(x);
    y = abs(y);
    if (a > b)
        swap(a, b);
    if (x > y)
        swap(x, y);
    return min(y * a * 2, x * a * 2 + (y - x) / 2 * (a + b));
}

void solve()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    x = abs(x);
    y = abs(y);
    ll ans;
    if ((x + y) % 2)
    {
        ans = f(a, b, x - 1, y) + a;
        ans = min(ans, f(a, b, x + 1, y) + a);
        ans = min(ans, f(a, b, x, y - 1) + b);
        ans = min(ans, f(a, b, x, y + 1) + b);
    }
    else
        ans = f(a, b, x, y);
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}