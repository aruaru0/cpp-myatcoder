#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];

    vector<mint> dp(n + 1);
    dp[0] = 1;
    mint tot = 1;
    unordered_map<ll, mint> dpsum;
    dpsum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] += tot;
        dp[i] -= dpsum[s[i] - k];

        tot += dp[i];
        dpsum[s[i]] += dp[i];
    }

    cout << dp[n].val() << endl;
    return 0;
}