#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll &a, ll b) { a = max(a, b); }

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    vector dp(n, vector(k + 1, vector<ll>(2)));
    auto f = [&](auto f, int v, int p = -1) -> void
    {
        vector dp2(k + 1, vector<ll>(3));
        for (int u : to[v])
            if (u != p)
            {
                f(f, u, v);
                for (int i = k; i >= 0; --i)
                    for (int j = 2; j >= 0; --j)
                    {
                        rep(ni, k + 1) rep(nj, 2)
                        {
                            if (i + ni > k || j + nj > 2)
                                break;
                            chmax(dp2[i + ni][j + nj], dp2[i][j] + dp[u][ni][nj]);
                        }
                    }
            }
        rep(i, k + 1)
        {
            chmax(dp[v][i][0], dp2[i][0]);
            chmax(dp[v][i][1], dp2[i][1] + a[v]);
            if (i < k)
                chmax(dp[v][i + 1][0], dp2[i][2] + a[v]);
        }
    };
    f(f, 0);

    ll ans = dp[0][k][0];
    cout << ans << endl;
    return 0;
}