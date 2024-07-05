#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

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

struct S
{
    int val, y;
    S(int val = 0, int y = -1) : val(val), y(y) {}
};

S op(S a, S b)
{
    if (a.val > b.val)
        return a;
    if (a.val < b.val)
        return b;
    if (a.y < b.y)
        return a;
    return b;
}
S e() { return S(); }

S mapping(int f, S x)
{
    x.val += f;
    return x;
}
int composition(int f, int g) { return f + g; }
int id() { return 0; }

struct Rect
{
    int lx, rx, ly, ry;
    Rect(int lx = 0, int rx = 0, int ly = 0, int ry = 0) : lx(lx), rx(rx), ly(ly), ry(ry) {}
};
struct Event
{
    int l, r, val;
    Event(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val) {}
};

int main()
{
    int n;
    cin >> n;
    vector<Rect> rects;
    const int M = 1e9;
    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        rects.emplace_back(0, l, l + 1, r);
        rects.emplace_back(l + 1, r, r + 1, M + 1);
    }

    CC xs, ys;
    for (auto [lx, rx, ly, ry] : rects)
    {
        xs.add(lx);
        xs.add(rx);
        ys.add(ly);
        ys.add(ry);
    }
    vector<vector<Event>> events(xs.size());
    for (auto &&[lx, rx, ly, ry] : rects)
    {
        lx = xs(lx);
        rx = xs(rx);
        ly = ys(ly);
        ry = ys(ry);
        events[lx].emplace_back(ly, ry, 1);
        events[rx].emplace_back(ly, ry, -1);
    }

    lazy_segtree<S, op, e, int, mapping, composition, id> t(ys.size());
    rep(i, ys.size()) t.set(i, S(0, i));

    int ans = 0, ansl = 0, ansr = 1;
    rep(xi, xs.size())
    {
        for (auto [l, r, val] : events[xi])
        {
            t.apply(l, r, val);
        }
        S s = t.all_prod();
        // cout << s.val << ' ' << s.y << endl;
        if (ans < s.val)
        {
            ans = s.val;
            ansl = xs[xi];
            ansr = ys[s.y];
        }
    }

    cout << ansl << ' ' << ansr << endl;
    return 0;
}