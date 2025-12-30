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

ll op(ll a, ll b)
{
    return max(a, b);
}

ll e()
{
    return -inf;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(n + 1);
    rep(i, n) cin >> b[i + 1];
    vector<ll> c(n + 1);
    rep(i, n) cin >> c[i];

    rep(i, n - 1) a[i + 1] += a[i];
    rep(i, n) b[i + 1] += b[i];
    for (int i = n - 1; i >= 0; i--)
        c[i] += c[i + 1];

    segtree<ll, op, e> seg(n + 1);

    rep(i, n + 1) seg.set(i, b[i] + c[i]);

    ll ans = -inf;
    rep(i, n - 2)
    {
        ll pre = a[i] - b[i + 1];
        ll post = seg.prod(i + 2, n);
        ans = max(ans, pre + post);
    }

    cout << ans << endl;

    return 0;
}
