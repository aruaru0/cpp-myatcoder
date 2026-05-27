#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;

mint comb(ll n, int k)
{
    mint a = 1, b = 1;
    rep(i, k) a *= n - i, b *= i + 1;
    return a / b;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int p;
        cin >> p;
        to[p - 1].push_back(i + 1);
    }
    vector<ll> c(n), d(n);
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> d[i];

    mint ans = 1;
    auto f = [&](auto f, int v) -> ll
    {
        ll num = c[v];
        for (int u : to[v])
            num += f(f, u);
        ans *= comb(num, d[v]);
        num -= d[v];
        return num;
    };
    f(f, 0);
    cout << ans.val() << endl;
    return 0;
}