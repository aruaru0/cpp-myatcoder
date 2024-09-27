#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(m), y(m);
    rep(i, m)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    deque<mint> dp(n);
    dp[0] = 1;

    rep(ki, k)
    {
        vector<mint> val(m);
        rep(i, m) val[i] = dp[x[i]];
        dp.push_front(dp.back());
        dp.pop_back();
        rep(i, m) dp[y[i]] += val[i];
    }

    mint ans;
    rep(i, n) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}