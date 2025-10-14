#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> to(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
    }

    vector dp(k * 2 + 1, vector<int>(n));
    rep(v, n)
    {
        dp[k * 2][v] = (s[v] == 'A'); // win:1, lose:0
    }

    for (int i = k * 2 - 1; i >= 0; i--)
    {
        rep(v, n)
        {
            dp[i][v] = 0;
            for (int u : to[v])
            {
                if (!dp[i + 1][u])
                    dp[i][v] = 1;
            }
        }
    }

    if (dp[0][0])
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}