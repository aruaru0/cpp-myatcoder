#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmin(ll &a, ll b) { a = min(a, b); }

int main()
{
    int n, m;
    cin >> n >> m;
    const ll INF = 1e18;
    n++;
    vector d(n, vector<ll>(n, INF));
    rep(i, n) d[i][i] = 0;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        chmin(d[a][b], c);
        chmin(d[b][a], c);
    }
    int k, T;
    cin >> k >> T;
    rep(i, k)
    {
        int a;
        cin >> a;
        chmin(d[a][0], T);
        chmin(d[0][a], 0);
    }

    rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
    ll ans = 0;
    auto add = [&](int a, int b, int sign = 1)
    {
        if (a == 0 || b == 0)
            return;
        if (d[a][b] != INF)
            ans += d[a][b] * sign;
    };
    rep(i, n) rep(j, n) add(i, j);

    auto upd = [&](int a, int b, ll c)
    {
        rep(i, n) rep(j, n)
        {
            add(i, j, -1);
            chmin(d[i][j], d[i][a] + c + d[b][j]);
            add(i, j);
        }
    };

    int q;
    cin >> q;
    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            upd(a, b, c);
            upd(b, a, c);
        }
        if (type == 2)
        {
            int a;
            cin >> a;
            upd(a, 0, T);
            upd(0, a, 0);
        }
        if (type == 3)
        {
            cout << ans << '\n';
        }
    }
    return 0;
}