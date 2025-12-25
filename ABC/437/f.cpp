#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

const ll inf = 1e18;

struct S
{
    ll p1, p2, p3, p4;
};

S e()
{
    return S{-inf, -inf, -inf, -inf};
}

S op(S a, S b)
{
    return S{max(a.p1, b.p1), max(a.p2, b.p2), max(a.p3, b.p3), max(a.p4, b.p4)};
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<S> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = S{x + y, x - y, -x + y, -x - y};
    }

    segtree<S, op, e> seg(v);

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x, y;
            cin >> i >> x >> y;
            i--;
            seg.set(i, S{x + y, x - y, -x + y, -x - y});
        }
        else
        {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            l--;
            S res = seg.prod(l, r);
            ll ans = -inf;
            ans = max(ans, res.p1 - (x + y));
            ans = max(ans, res.p2 - (x - y));
            ans = max(ans, res.p3 - (-x + y));
            ans = max(ans, res.p4 - (-x - y));

            cout << ans << endl;
        }
    }

    return 0;
}
