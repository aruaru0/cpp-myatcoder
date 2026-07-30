#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int ans = 0;
    int mx = 0, lis = 0;
    const int INF = 1001001001;
    vector<int> dp(n, INF);
    rep(i, n)
    {
        if (mx < p[i])
        {
            mx = p[i];
            ans++;
        }
        else
        {
            int j = lower_bound(dp.begin(), dp.end(), p[i]) - dp.begin();
            lis = max(lis, j + 1);
            dp[j] = p[i];
        }
    }
    ans += lis;
    cout << ans << endl;
    return 0;
}