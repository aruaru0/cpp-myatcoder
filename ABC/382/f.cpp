#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using BARS = tuple<int, int, int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct S
{
    int a;
};
struct F
{
    int a;
};

S op(S l, S r) { return S{max(l.a, r.a)}; }

S e() { return S{0}; }

S mapping(F l, S r) { return S{max(l.a, r.a)}; }

F composition(F l, F r) { return F{max(l.a, r.a)}; }

F id() { return F{0}; }

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    // r, c, l, idxの４つの要素のベクトルを作成
    vector<BARS> v;
    rep(i, n)
    {
        int r, c, l;
        cin >> r >> c >> l;
        v.push_back(BARS(r, c, l, i));
    }

    // rの大きい順にソート
    sort(v.begin(), v.end(), [](BARS a, BARS b)
         { return get<0>(a) > get<0>(b); });

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(w + 1);

    vector<int> ans(n);
    rep(i, n)
    {
        auto [r, c, l, idx] = v[i];
        S pos = seg.prod(c, c + l);
        ans[idx] = h - pos.a;
        seg.apply(c, c + l, F{pos.a + 1});
    }

    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}
