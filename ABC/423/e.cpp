#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector s(3, vector<ll>(n + 1));
    rep(k, 3)
    {
        rep(i, n)
        {
            ll x = a[i];
            rep(j, k) x *= i;
            s[k][i + 1] = s[k][i] + x;
        }
    }

    rep(qi, q)
    {
        int l, r;
        cin >> l >> r;
        l--;

        ll ans = 0;
        ans -= (s[2][r] - s[2][l]);
        ans += (s[1][r] - s[1][l]) * (l - 1 + r);
        ans -= (s[0][r] - s[0][l]) * (ll(l - 1) * r);

        cout << ans << '\n';
    }
    return 0;
}