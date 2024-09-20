#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

const int INF = 1001001001;
struct S
{
    int mx, len;
    ll sum;
    S(int mx = -INF, int len = 0, ll sum = 0) : mx(mx), len(len), sum(sum) {}
};

S op(S a, S b)
{
    S res;
    res.mx = max(a.mx, b.mx);
    res.len = a.len + b.len;
    res.sum = a.sum + b.sum;
    return res;
}
S e() { return S(); }

S mapping(int f, S x)
{
    if (f == -1)
        return x;
    x.mx = f;
    x.sum = (ll)f * x.len;
    return x;
}
int composition(int f, int g)
{
    if (f == -1)
        return g;
    return f;
}
int id() { return -1; }

int main()
{
    int n;
    cin >> n;

    lazy_segtree<S, op, e, int, mapping, composition, id> t(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        x -= i;
        t.set(i, S(x, 1, x));
    }

    ll ans = 0;
    int q;
    cin >> q;
    rep(qi, q)
    {
        int i, g;
        cin >> i >> g;
        i--;
        g -= i;

        int x = t.get(i).mx;
        int j = 0;
        {
            auto f = [&](S a) -> bool
            {
                return a.mx < g;
            };
            j = t.max_right(0, f);
        }
        if (x < g)
        {
            int l = i, r = j;
            ans += g * ll(r - l) - t.prod(l, r).sum;
            t.apply(l, r, g);
        }
        else
        {
            int l = j, r = i + 1;
            ans += t.prod(l, r).sum - g * ll(r - l);
            t.apply(l, r, g);
        }
    }

    cout << ans << endl;
    return 0;
}