#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmin(int &a, int b) { a = min(a, b); }

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    const int INF = 1001001001;
    vector dp(n + 1, vector<int>(3, INF));
    rep(j, 3) dp[0][j] = 0;
    rep(i, n)
    {
        rep(j, 3)
        {
            int cost = ((s[i] - '0') == (j % 2)) ? 0 : 1;
            chmin(dp[i + 1][j], dp[i][j] + cost);
        }
        rep(j, 2) chmin(dp[i + 1][j + 1], dp[i + 1][j]);
    }

    int ans = dp[n][2];
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(i, T) solve();
    return 0;
}