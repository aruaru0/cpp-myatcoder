#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

struct S
{
    mint a, b, c, s;
};

struct F
{
    mint a, b;
};

S op(S l, S r)
{
    return S{
        l.a + r.a,
        l.b + r.b,
        l.c + r.c,
        l.s + r.s};
}

S e()
{
    return S{0, 0, 0, 0};
}

S mapper(F f, S x)
{
    return S{
        x.a + x.c * f.a,
        x.b + x.c * f.b,
        x.c,
        x.s + x.a * f.b + x.b * f.a + x.c * f.a * f.b};
}

F comp(F f, F g)
{
    return F{f.a + g.a, f.b + g.b};
}

F id()
{
    return F{0, 0};
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> b(n);
    rep(i, n)
    {
        cin >> b[i];
    }

    vector<S> v(n);
    rep(i, n)
    {
        v[i] = S{a[i], b[i], 1, (mint)a[i] * b[i]};
    }

    lazy_segtree<S, op, e, F, mapper, comp, id> seg(v);

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, F{x, 0});
        }
        else if (t == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, F{0, x});
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r).s.val() << endl;
        }
    }
}