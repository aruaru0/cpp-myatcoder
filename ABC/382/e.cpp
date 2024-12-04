#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> per(n);
    rep(i, n) cin >> per[i];

    vector<double> P(1, 1);
    rep(i, n)
    {
        vector<double> old(i + 2);
        swap(old, P);
        double p = per[i] / 100.;
        rep(j, i + 1)
        {
            P[j] += old[j] * (1 - p);
            P[j + 1] += old[j] * p;
        }
    }

    vector<double> dp(x + 1);
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i] += dp[max(i - j, 0)] * P[j];
        }
        dp[i] += 1;
        dp[i] /= 1 - P[0];
    }

    printf("%.10f\n", dp[x]);
    return 0;
}