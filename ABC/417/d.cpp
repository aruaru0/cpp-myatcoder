#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    rep(i, n) cin >> p[i] >> a[i] >> b[i];
    const int m = 1001;
    vector dp(n + 1, vector<int>(m));
    rep(i, m) dp[n][i] = i;
    for (int i = n - 1; i >= 0; i--)
    {
        rep(j, m)
        {
            int nj;
            if (j <= p[i])
                nj = j + a[i];
            else
                nj = max(0, j - b[i]);
            dp[i][j] = dp[i + 1][nj];
        }
    }

    vector<int> bs(n + 1);
    rep(i, n) bs[i + 1] = bs[i] + b[i];

    int q;
    cin >> q;
    rep(qi, q)
    {
        int x;
        cin >> x;
        int ans;
        if (x >= m)
        {
            int i = upper_bound(bs.begin(), bs.begin() + n, x - m) - bs.begin();
            x -= bs[i];
            if (i < n)
                ans = dp[i][x];
            else
                ans = x;
        }
        else
        {
            ans = dp[0][x];
        }
        cout << ans << '\n';
    }
    return 0;
}