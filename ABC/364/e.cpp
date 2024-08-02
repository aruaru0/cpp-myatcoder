#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int inf = 99999;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, inf));
    dp[0][0] = 0;

    rep(i, n)
    {
        vector<vector<int>> tmp(n + 1, vector<int>(x + 1, inf));
        rep(j, i + 1)
        {
            rep(k, x + 1)
            {
                tmp[j][k] = min(tmp[j][k], dp[j][k]);
                if (k + a[i] <= x)
                {
                    tmp[j + 1][k + a[i]] = min(tmp[j + 1][k + a[i]], dp[j][k] + b[i]);
                }
            }
        }
        dp = tmp;
        // rep(j, n + 1) rep(k, x + 1)
        // {
        //     cout << dp[j][k] << " ";
        // }
        // cout << endl;
    }

    int ans = 0;
    rep(i, n + 1) rep(j, x + 1)
    {
        if (dp[i][j] <= y)
        {
            ans = max(ans, i);
        }
    }
    cout << min(n, ans + 1) << endl;
}