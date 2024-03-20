#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
const ll INF = 1e18;

struct D
{
    ll val, col;
    D(ll val = -INF, int col = -1) : val(val), col(col) {}
};

struct TOP2
{
    D a, b;
    TOP2(D a = D(), D b = D(-INF, -2)) : a(a), b(b) {}
    void operator<=(D d)
    {
        if (b.val < d.val)
        {
            swap(b, d);
            if (a.val < b.val)
            {
                swap(a, b);
            }
        }
        if (a.col == b.col)
        {
            b = d;
        }
    };
    void operator<=(TOP2 x)
    {
        *this <= x.a;
        *this <= x.b;
    }
    ll get(int c)
    {
        if (a.col == c)
            return b.val;
        return a.val;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n), v(n);
    rep(i, n) cin >>
        c[i] >> v[i];

    vector<TOP2> dp(k + 1);
    dp[0] = TOP2(D(0, -1));

    rep(i, n)
    {
        vector<TOP2> tmp(k + 1);
        rep(j, k + 1)
        {
            if (j < k)
            {
                tmp[j + 1] = dp[j];
            }
            tmp[j] <= D(dp[j].get(c[i]) + v[i], c[i]);
        }
        swap(dp, tmp);
    }

    ll ans = dp[k].a.val;
    if (ans < 0)
        ans = -1;
    cout << ans << endl;
    return 0;
}
