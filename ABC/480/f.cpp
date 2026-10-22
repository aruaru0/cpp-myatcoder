#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int n2 = 1 << n;
    vector<ll> sum(n2);
    rep(i, n)
    {
        rep(j, 1 << i) sum[j | 1 << i] = sum[j] + a[i];
    }

    ll w = sum[n2 - 1] / m;

    vector<int> dp(n2);
    rep(s, n2)
    {
        rep(i, n) if (~s >> i & 1)
        {
            int ns = s | 1 << i;
            dp[ns] = max(dp[ns], dp[s] + !(sum[ns] % w));
        }
    }

    cout << m - dp[n2 - 1] << endl;
    return 0;
}