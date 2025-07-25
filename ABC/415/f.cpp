#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmax(int &a, int b) { a = max(a, b); }

struct S
{
    int ans;
    char lc;
    int l;
    char rc;
    int r;
    bool same;
};

S op(S a, S b)
{
    S res;
    res.ans = max(a.ans, b.ans);
    if (a.rc == b.lc)
        chmax(res.ans, a.r + b.l);
    res.lc = a.lc;
    res.l = a.l;
    res.rc = b.rc;
    res.r = b.r;
    if (a.same && a.lc == b.lc)
        res.l += b.l;
    if (b.same && a.rc == b.rc)
        res.r += a.r;
    res.same = a.same && b.same && a.lc == b.lc;
    return res;
}
S e() { return S(0, '?', 0, '?', 0, false); }
S newS(char c) { return S(1, c, 1, c, 1, true); }

int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    segtree<S, op, e> t(n);
    rep(i, n) t.set(i, newS(s[i]));

    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i;
            char x;
            cin >> i >> x;
            --i;
            t.set(i, newS(x));
        }
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            --l;
            cout << t.prod(l, r).ans << '\n';
        }
    }
    return 0;
}