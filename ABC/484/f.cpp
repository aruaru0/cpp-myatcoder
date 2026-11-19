#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1001001001;
int e() { return -1; }
int op(int a, int b)
{
    if (a == INF || b == INF)
        return INF;
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (a == b)
        return a;
    return INF;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    segtree<int, op, e> t(a);

    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, x;
            cin >> i >> x;
            --i;
            t.set(i, x);
        }
        if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            --l;
            if (t.prod(l, r) == INF)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
    return 0;
}