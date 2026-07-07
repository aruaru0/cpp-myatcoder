#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    int ans = 0;
    while (x != y)
    {
        if (x > y)
            x /= k;
        else
            y /= k;
        ans++;
    }
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}