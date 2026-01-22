#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n), v(n);
    rep(i, n) cin >> p[i] >> v[i];

    auto calcDP = [&]()
    {
        vector dp(n + 1, vector<ll>(m + 1, 0));
        rep(i, n)
        {
            dp[i + 1] = dp[i];
            rep(j, m + 1 - p[i]) chmax(dp[i + 1][j + p[i]], dp[i][j] + v[i]);
        }
        return dp;
    };

    auto dpl = calcDP();
    reverse(p.begin(), p.end());
    reverse(v.begin(), v.end());
    auto dpr = calcDP();
    reverse(p.begin(), p.end());
    reverse(v.begin(), v.end());
    reverse(dpr.begin(), dpr.end());

    auto getMax = [&](vector<ll> &dl, vector<ll> &dr, int mx)
    {
        ll res = 0;
        rep(i, mx + 1) chmax(res, dl[i] + dr[mx - i]);
        return res;
    };

    string ans;
    rep(i, n)
    {
        ll a = getMax(dpl[i], dpr[i + 1], m - p[i]) + v[i];
        ll c = getMax(dpl[i], dpr[i + 1], m);
        if (a == c)
            ans += 'B';
        else if (a > c)
            ans += 'A';
        else
            ans += 'C';
    }
    cout << ans << endl;
    return 0;
}