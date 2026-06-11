#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

int main()
{
    ll n;
    cin >> n;
    vector<ll> ds;
    {
        set<ll> s;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
                s.insert(i), s.insert(n / i);
        }
        ds = vector<ll>(s.begin(), s.end());
    }

    const int m = 13;
    vector<map<ll, pair<mint, mint>>> dp(m + 1);
    dp[0][1] = {1, 0};
    dp[1][1] = {1, 1};
    for (ll d : ds)
        if (d > 1)
        {
            for (int i = m - 1; i >= 0; i--)
            {
                for (auto [p, cs] : dp[i])
                {
                    auto [c, s] = cs;
                    if (n / p % d)
                        continue;
                    ll np = p * d;
                    dp[i + 1][np].first += c;
                    dp[i + 1][np].second += s + c * d;
                }
            }
        }

    vector<mint> fac(m + 1, 1);
    rep(i, m) fac[i + 1] = fac[i] * (i + 1);

    mint ans;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[i][n].second * fac[i];
    }
    cout << ans.val() << endl;
    return 0;
}