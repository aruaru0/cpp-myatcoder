#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int op(int x, int y) { return max(x, y); }
int e() { return 0; }

int mapping(int f, int x) { return x + f; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> pre(n);
    {
        vector<int> pos(n + 1, -1);
        rep(i, n)
        {
            pre[i] = pos[a[i]];
            pos[a[i]] = i;
        }
    }

    using seg = lazy_segtree<int, op, e, int, mapping, composition, id>;
    vector<seg> t(3, seg(n));

    rep(i, n)
    {
        rep(j, 2)
        {
            int now = t[j].all_prod();
            t[j + 1].set(i, now);
        }
        rep(j, 3)
        {
            t[j].apply(pre[i] + 1, i + 1, 1);
        }
    }
    int ans = t[2].all_prod();
    cout << ans << endl;
    return 0;
}