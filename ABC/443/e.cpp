#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    rep(i, n) s[i] = "#" + s[i] + "#";
    int w = n + 2;

    vector dp(n, vector<bool>(w));
    dp[n - 1][c] = true;

    vector<int> bottom(w, n);
    rep(i, n) rep(j, w) if (s[i][j] == '#') bottom[j] = i;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!dp[i + 1][j - 1] && !dp[i + 1][j] && !dp[i + 1][j + 1])
                continue;
            if (s[i][j] == '#')
            {
                if (bottom[j] != i)
                    continue;
                rep(ni, n) s[ni][j] = '.';
            }
            dp[i][j] = true;
        }
    }

    string ans;
    for (int j = 1; j <= n; j++)
        ans += '0' + dp[0][j];
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}