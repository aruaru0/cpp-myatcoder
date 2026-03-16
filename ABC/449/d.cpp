#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ll l, r, d, u;
    cin >> l >> r >> d >> u;

    ll ans = 0;
    for (ll w = 0; w <= 1e6; w++)
    {
        int sign = w % 2 ? -1 : 1;
        ll nl = max(-w, l), nr = min(w, r);
        ll nd = max(-w, d), nu = min(w, u);
        if (nl <= nr && nd <= nu)
            ans += (nr - nl + 1) * (nu - nd + 1) * sign;
    }
    cout << ans << endl;
    return 0;
}