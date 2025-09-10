#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmin(ll &a, ll b) { a = min(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> w(n);
    rep(i, n) cin >> w[i];
    vector<vector<int>> to(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    const ll INF = 1e18;
    vector dp(n + 1, vector<ll>(n, INF));
    rep(i, n + 1) dp[i][0] = w[0] * i;

    for (int i = n - 1; i >= 0; i--)
    {
        rep(v, n)
        {
            for (int u : to[v])
            {
                chmin(dp[i][u], dp[i + 1][v] + w[u] * i);
            }
        }
    }

    rep(v, n) cout << dp[0][v] << endl;
    return 0;
}