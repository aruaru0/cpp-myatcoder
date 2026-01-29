#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmin(int &a, int b) { a = min(a, b); }

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[n - 1 - i];

    const int INF = 1001001001;
    vector dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    vector cost_r(n, vector<int>(n + 1));
    rep(i, n) rep(j, n)
    {
        cost_r[i][j + 1] = cost_r[i][j] + (s[i][j] == '#');
    }
    vector cost_c(n + 1, vector<int>(n));
    rep(i, n) rep(j, n)
    {
        cost_c[i + 1][j] = cost_c[i][j] + (s[i][j] == '.');
    }

    rep(i, n + 1) rep(j, n + 1)
    {
        if (i < n)
            chmin(dp[i + 1][j], dp[i][j] + cost_r[i][j]);
        if (j < n)
            chmin(dp[i][j + 1], dp[i][j] + cost_c[i][j]);
    }
    cout << dp[n][n] << endl;
    return 0;
}