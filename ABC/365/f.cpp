#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

const int INF = 1001001001;
struct S
{
    int l, r;
    ll d;
    S(int l = 0, int r = INF, ll d = -1) : l(l), r(r), d(d) {}
    pair<int, ll> operator()(int s)
    {
        if (d == -1)
        {
            if (s < l)
                return {l, l - s};
            if (s > r)
                return {r, s - r};
            return {s, 0ll};
        }
        else
        {
            return {r, d + abs(s - l)};
        }
    }
};
S op(S a, S b)
{
    if (a.d == -1)
    {
        if (b.d == -1)
        { // AA
            if (a.r < b.l)
                return S(a.r, b.l, b.l - a.r);
            if (a.l > b.r)
                return S(a.l, b.r, a.l - b.r);
            return S(max(a.l, b.l), min(a.r, b.r), -1);
        }
        else
        { // AB
            auto [t, d] = a(b.l);
            return S(t, b.r, b.d + d);
        }
    }
    else
    { // B?
        auto [t, d] = b(a.r);
        return S(a.l, t, a.d + d);
    }
}
S e() { return S(); }

int main()
{
    int n;
    cin >> n;
    segtree<S, op, e> t(n);
    rep(i, n)
    {
        int l, u;
        cin >> l >> u;
        t.set(i, S(l, u));
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        if (sx > tx)
            swap(sx, tx), swap(sy, ty);
        sx--;
        tx--;
        auto [y, d] = t.prod(sx, tx)(sy);
        d += abs(y - ty);
        d += tx - sx;
        cout << d << '\n';
    }
    return 0;
}