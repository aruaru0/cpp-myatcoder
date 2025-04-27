#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int maxn = 1e6 + 10;
    vector<int> b(maxn, 0);
    rep(i, n) b[a[i]]++;

    if (d == 0)
    {
        int ans = 0;
        rep(i, maxn)
        {
            ans += max(0, b[i] - 1);
        }
        cout << ans << endl;
        return 0;
    }

    const int inf = 1e6;
    int ans = 0;
    rep(i, d)
    {
        vector<int> cnt;
        for (int j = i; j < maxn; j += d)
        {
            cnt.push_back(b[j]);
        }
        vector<vector<int>> dp(cnt.size() + 1, vector<int>(2, inf));
        dp[0][0] = 0;
        rep(j, cnt.size())
        {
            // 使わない場合は、除去コストを追加
            // 前の状態はどうでも良い
            dp[j + 1][0] = min(dp[j][0], dp[j][1]) + cnt[j];
            // 残す場合は、１つ前は除去していること
            dp[j + 1][1] = dp[j][0];
        }
        ans += min(dp[cnt.size()][0], dp[cnt.size()][1]);
    }

    cout << ans << endl;
    return 0;
}
