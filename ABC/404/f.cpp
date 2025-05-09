#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmax(double &a, double b) { a = max(a, b); }

int main()
{
    int n, t, m, k;
    cin >> n >> t >> m >> k;
    vector dp(t + 1, vector<double>(k + 1));
    dp[t][k] = 1;

    for (int ti = t - 1; ti >= 0; ti--)
    {
        rep(kj, k + 1)
        {
            double now = 0;
            {
                vector dp2(m + 1, vector<double>(m + 1));
                rep(i, m) rep(j, m + 1)
                {
                    for (int c = 1; j + c <= m; c++)
                    {
                        chmax(dp2[i + 1][j + c], dp2[i][j] + dp[ti + 1][min(k, kj + c)]);
                    }
                }
                rep(i, m + 1)
                {
                    if (i > n)
                        break;
                    double x = dp2[i][m];
                    x += dp[ti + 1][kj] * (n - i);
                    chmax(now, x);
                }
            }
            dp[ti][kj] = now / n;
        }
    }

    double ans = dp[0][0];
    printf("%.10f\n", ans);
    return 0;
}