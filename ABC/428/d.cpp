#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll s(ll r)
{
    ll ac = 0, wa = 2e9;
    while (ac + 1 < wa)
    {
        ll wj = (ac + wa) / 2;
        if (wj * wj <= r)
            ac = wj;
        else
            wa = wj;
    }
    return ac;
}
ll s(ll l, ll r)
{
    return s(r) - s(l - 1);
}
ll g(ll c, ll r)
{
    ll res = 0;
    for (ll l = 1;; l *= 10)
    {
        ll base = c * l * 10;
        ll nl = base + l, nr = base + (l * 10 - 1);
        nr = min(nr, base + r);
        if (nr < nl)
            return res;
        res += s(nl, nr);
    }
}

void solve()
{
    ll c, d;
    cin >> c >> d;
    ll ans = g(c, c + d) - g(c, c);
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}