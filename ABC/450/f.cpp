#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

mint op(mint a, mint b) { return a + b; }
mint e() { return 0; }
mint mapping(mint f, mint x) { return x * f; }
mint composition(mint f, mint g) { return f * g; }
mint id() { return 1; }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rs(n);
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        rs[l].push_back(r);
    }

    lazy_segtree<mint, op, e, mint, mapping, composition, id> t(n);
    t.set(0, 1);

    rep(l, n)
    {
        for (int r : rs[l])
        {
            mint s = t.prod(l, r + 1);
            t.set(r, t.get(r) + s);
            t.apply(r + 1, n, 2);
        }
    }

    mint ans = t.get(n - 1);
    cout << ans.val() << endl;
    return 0;
}