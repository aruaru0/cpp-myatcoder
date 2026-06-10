#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    int m = q + 4;

    vector last(2, vector<int>(n));
    vector d(2, fenwick_tree<int>(m));
    rep(i, 2)
    {
        last[i] = vector<int>(n, i);
        d[i].add(i, n);
    }

    ll ans = 0;
    for (int t = 2; t < q + 2; t++)
    {
        int x, i;
        cin >> x >> i;
        --x;
        --i;
        int &l = last[x][i];
        int now = d[x ^ 1].sum(l, t);
        if (x)
            ans -= now;
        else
            ans += now;
        cout << ans << '\n';

        d[x].add(l, -1);
        l = t;
        d[x].add(l, 1);
    }
    return 0;
}