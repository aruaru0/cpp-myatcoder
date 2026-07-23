#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template <typename T = int>
struct CC
{
    bool initialized;
    vector<T> xs;
    CC() : initialized(false) {}
    void add(T x) { xs.push_back(x); }
    void init()
    {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        initialized = true;
    }
    int operator()(T x)
    {
        if (!initialized)
            init();
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
    }
    T operator[](int i)
    {
        if (!initialized)
            init();
        return xs[i];
    }
    int size()
    {
        if (!initialized)
            init();
        return xs.size();
    }
};

const ll INF = 1e18;
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }
ll mapping(ll f, ll x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), bid(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    using P = pair<int, int>;
    CC<P> cc;
    rep(i, n) cc.add(P(b[i], i)), bid[i] = i;

    vector<tuple<int, int, int>> qs;
    rep(qi, q)
    {
        int type, i, x;
        cin >> type >> i >> x;
        i--;
        qs.emplace_back(type, i, x);
        if (type == 2)
            cc.add(P(x, n + qi));
    }

    int m = cc.size();
    lazy_segtree<ll, op, e, ll, mapping, composition, id> t(m);
    auto add = [&](int i)
    {
        int j = cc(P(b[i], bid[i]));
        ll d = t.get(j) + INF;
        t.set(j, b[i] + d);
        t.apply(0, j + 1, a[i]);
    };
    auto del = [&](int i)
    {
        int j = cc(P(b[i], bid[i]));
        t.apply(0, j + 1, -a[i]);
        ll d = t.get(j) - b[i];
        t.set(j, d - INF);
    };
    rep(i, n) add(i);
    rep(qi, q)
    {
        auto [type, i, x] = qs[qi];
        del(i);
        if (type == 1)
            a[i] = x;
        else
            b[i] = x, bid[i] = n + qi;
        add(i);
        cout << t.all_prod() << '\n';
    }
    return 0;
}