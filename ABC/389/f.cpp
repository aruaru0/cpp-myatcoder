#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }
int mapping(int f, int x) { return x + f; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main()
{
    int n;
    cin >> n;

    const int m = 500005;
    vector<int> initial(m);
    rep(i, m) initial[i] = i;
    lazy_segtree<int, op, e, int, mapping, composition, id> t(initial);

    auto lwb = [&](int x)
    {
        auto f = [&](int a)
        { return a < x; };
        return t.max_right(0, f);
    };

    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        r++;
        int li = lwb(l), ri = lwb(r);
        t.apply(li, ri, 1);
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int x;
        cin >> x;
        int ans = t.get(x);
        cout << ans << '\n';
    }
    return 0;
}