#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, W;
    cin >> n >> W;

    // 重さごとに優先キューに入れる
    vector<priority_queue<ll>> qs(W + 1);
    rep(i, n)
    {
        int w, v;
        cin >> w >> v;
        qs[w].push(v - 1);
    }

    vector<ll> dp(W + 1);

    for (int w = 1; w <= W; w++)
    {
        if (qs[w].size() == 0)
            continue;

        // 前処理
        int m = W / w;
        vector<ll> d(m + 1);
        for (int i = 1; i <= m; i++)
        {
            ll diff = qs[w].top();
            qs[w].pop();
            d[i] = d[i - 1] + diff;
            qs[w].push(diff - 2);
        }

        // 箱に入れる
        for (int i = W; i >= 0; i--)
        {
            for (int j = 1; j <= m; j++)
            {
                int ni = i + j * w;
                if (ni > W)
                    break;
                dp[ni] = max(dp[ni], dp[i] + d[j]);
            }
        }
    }

    cout << dp[W] << endl;
    return 0;
}