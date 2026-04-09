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

const int INF = 1001001001;
struct S
{
    int val, num;
};
S op(S a, S b)
{
    if (a.val < b.val)
        return a;
    if (a.val > b.val)
        return b;
    a.num += b.num;
    return a;
}
S e() { return S(INF, 0); }

S mapping(int f, S x)
{
    x.val += f;
    return x;
}
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main()
{
    int H, W, h, w, n;
    cin >> H >> W >> h >> w >> n;

    H -= h - 1;
    W -= w - 1;

    CC cc;
    map<int, vector<tuple<int, int, int>>> events;
    cc.add(0);
    cc.add(W);
    rep(i, n)
    {
        int r, c;
        cin >> r >> c;
        int sr = r - h, sc = c - w;
        sr = max(sr, 0);
        sc = max(sc, 0);
        r = min(r, H);
        c = min(c, W);
        events[sr].emplace_back(sc, c, 1);
        events[r].emplace_back(sc, c, -1);
        cc.add(sc);
        cc.add(c);
    }
    events[H].emplace_back(0, 0, 0);

    int m = cc.size();
    lazy_segtree<S, op, e, int, mapping, composition, id> seg(m);
    rep(i, m - 1)
    {
        seg.set(i, S(0, cc[i + 1] - cc[i]));
    }

    ll ans = 0;
    ll pr = 0;
    for (auto [row, qs] : events)
    {
        S s = seg.all_prod();
        if (s.val == 0)
            ans += (row - pr) * s.num;
        for (auto [l, r, x] : qs)
            seg.apply(cc(l), cc(r), x);
        pr = row;
    }
    cout << ans << endl;
    return 0;
}