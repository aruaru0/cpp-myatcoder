#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, x;
    cin >> n >> x;
    int n2 = 1 << n;
    vector<tuple<int, int, double>> ps;
    rep(i, n)
    {
        int s, c, p;
        cin >> s >> c >> p;
        ps.emplace_back(s, c, p / 100.);
    }
    vector dp(x + 1, vector<double>(n2));

    rep(i, x + 1) rep(s, n2)
    {
        rep(j, n)
        {
            if (s >> j & 1)
                continue;
            auto [score, c, p] = ps[j];
            if (c > i)
                continue;
            double now = dp[i - c][s] * (1 - p) + (dp[i - c][s | 1 << j] + score) * p;
            dp[i][s] = max(dp[i][s], now);
        }
    }

    double ans = dp[x][0];
    printf("%.10f\n", ans);
    return 0;
}