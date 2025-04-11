#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmin(ll &x, ll y) { x = min(x, y); }

int main()
{
    int n;
    cin >> n;
    vector<int> c(n), x(n);
    rep(i, n) cin >> c[i], c[i]--;
    rep(i, n) cin >> x[i];

    const ll INF = 1e18;
    vector dp(n, vector<ll>(n, INF));
    vector dp2(n, vector<ll>(n, INF));
    rep(i, n) dp2[i][i] = x[c[i]];

    auto get = [&](int l, int r)
    {
        l = (l + n) % n;
        r = (r + n) % n;
        return dp[l][r];
    };
    auto get2 = [&](int l, int r)
    {
        l = (l + n) % n;
        r = (r + n) % n;
        return dp2[l][r];
    };

    for (int w = 1; w <= n; w++)
    {
        rep(l, n)
        {
            int r = (l + w - 1) % n;
            if (w > 1 && c[l] == c[r])
                chmin(dp2[l][r], get2(l, r - 1));
            rep(i, w - 1) chmin(dp2[l][r], get2(l, l + i) + get(l + i + 1, r));

            chmin(dp[l][r], dp2[l][r] + w);
            rep(i, w - 1)
            {
                chmin(dp[l][r], get(l, l + i) + get(l + i + 1, r));
            }
        }
    }

    ll ans = INF;
    rep(l, n) chmin(ans, get(l, l + n - 1));
    cout << ans << endl;
    return 0;
}