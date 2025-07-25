#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    int h, w;
    cin >> h >> w;
    vector a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    int n = h + w - 1;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    const ll INF = 1e18;
    auto judge = [&](ll x)
    {
        vector dp(h, vector<ll>(w, -INF));
        dp[0][0] = x;
        rep(i, h) rep(j, w)
        {
            dp[i][j] += a[i][j];
            dp[i][j] -= p[i + j];
            if (dp[i][j] < 0)
                dp[i][j] = -INF;
            if (i + 1 < h)
                chmax(dp[i + 1][j], dp[i][j]);
            if (j + 1 < w)
                chmax(dp[i][j + 1], dp[i][j]);
        }
        return dp[h - 1][w - 1] >= 0;
    };

    ll ac = 1e15, wa = -1;
    while (ac - wa > 1)
    {
        ll wj = (ac + wa) / 2;
        if (judge(wj))
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << endl;
    return 0;
}