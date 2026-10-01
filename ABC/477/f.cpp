#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct S
{
    ll sum, len;
};
S op(S a, S b) { return S(a.sum + b.sum, a.len + b.len); }
S e() { return S(0, 0); }
S mapping(ll f, S x) { return S(x.sum + f * x.len, x.len); }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> L(n), R(n);
    rep(i, n) cin >> L[i] >> R[i], L[i]--;

    vector<vector<tuple<int, int, int>>> qs(n);
    rep(qi, q)
    {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        u -= 2;
        d--;
        l--;
        if (u >= 0)
            qs[u].emplace_back(l, r, q + qi);
        qs[d].emplace_back(l, r, qi);
    }

    lazy_segtree<S, op, e, ll, mapping, composition, id> seg(m);
    rep(i, m) seg.set(i, S(0, 1));

    vector<ll> ans(q);
    rep(i, n)
    {
        seg.apply(L[i], R[i], 1);
        for (auto [l, r, qi] : qs[i])
        {
            int sign = 1;
            if (qi >= q)
                qi -= q, sign = -1;
            ans[qi] += seg.prod(l, r).sum * sign;
        }
    }

    rep(i, q) cout << ans[i] << '\n';
    return 0;
}