#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using namespace atcoder;
using mint = modint998244353;

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

struct S
{
    mint val;
    int cnt;
};

struct F
{
    mint a;
    int cnt;
};

S op(S l, S r)
{
    return S{l.val + r.val, l.cnt + r.cnt};
}

S e() { return S{0, 0}; }

S mapping(F l, S r)
{
    if (l.cnt == -1)
        return r;
    return S{r.cnt * l.a, r.cnt};
}

F composition(F l, F r)
{
    if (l.cnt > r.cnt)
        return l;
    return r;
}

F id() { return F{0, -1}; }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<S> v(n);
    rep(i, n) v[i] = S{a[i], 1};

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    vector<mint> iv(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        iv[i] = (mint)1 / i;
    }

    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        l--;
        mint tot = seg.prod(l, r).val;
        mint e = tot * iv[r - l];
        seg.apply(l, r, F{e, i});
    }

    rep(i, n)
    {
        cout << seg.get(i).val.val() << " ";
    }
    cout << endl;

    return 0;
}
