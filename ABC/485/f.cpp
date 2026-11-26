#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;

    ll tot = 0;
    vector<vector<int>> vs(m + 1);
    rep(i, n)
    {
        int c, v;
        cin >> c >> v;
        vs[c].push_back(v);
        tot += v;
    }

    vector<ll> ans(m + 1);
    const ll INF = 1e18;
    vector dp(n + 1, deque<ll>(m + 1, -INF));
    dp[0] = deque<ll>(m + 1, 0);
    for (int k = m; k >= 0; k--)
    {
        for (int v : vs[k])
        {
            tot -= v;
            for (int i = n - 1; i >= 0; i--)
                rep(j, m + 1)
                {
                    chmax(dp[i + 1][j], dp[i][j] + v);
                }
        }

        ll now = -INF;
        rep(i, n + 1) chmax(now, dp[i][m]);
        ans[k] = now + tot;

        rep(i, n + 1)
        {
            rep(j, i)
            {
                dp[i].push_front(-INF);
                dp[i].pop_back();
            }
        }
    }

    rep(i, m + 1) cout << ans[i] << '\n';
    return 0;
}