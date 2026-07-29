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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<mint> b(n);
    rep(i, n) b[i] = mint(i + 1).inv();
    vector<mint> sa(n + 1), sb(n + 1);
    rep(i, n) sa[i + 1] = sa[i] + a[i];
    rep(i, n) sb[i + 1] = sb[i] + b[i];
    mint ans;
    for (int l = 0, r = n; l < r; l++, r--)
    {
        ans += (sa[r] - sa[l]) * (sb[r] - sb[l]);
    }
    cout << ans.val() << endl;
    return 0;
}