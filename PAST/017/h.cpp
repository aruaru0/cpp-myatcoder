#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define chmin(a, b) ((a) = min((a), (b)))

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> s(5001, vector<pair<int, int>>());
    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        s[b - 1].push_back({a, c});
    }

    const int inf = 1e9;
    vector<vector<int>> dp(5001, vector<int>(m + 1, inf));
    dp[0][0] = 0;
    rep(t, 5000)
    {
        rep(i, m + 1)
        {
            chmin(dp[t + 1][i], dp[t][i]);
            for (auto e : s[t])
            {
                int nxt = min(m, i + e.second);
                chmin(dp[t + 1][nxt], dp[t][i] + e.first);
            }
        }
    }

    int ans = dp[5000][m];
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}