#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector c(n, vector<int>(n));
    rep(i, n) rep(j, n)
    {
        c[i][j] = a[i] * b[j] % m;
    }

    int w = n * 3;
    vector d(w, vector<ll>(w));
    { // blue
        vector e(w, vector<ll>(w));
        rep(i, n) rep(j, n)
        {
            e[i + 2][j + 2] -= c[i][j];
            e[i + n * 2][j + n * 2] += c[i][j];
        }
        rep(i, w - 1) rep(j, w - 1) e[i + 1][j + 1] += e[i][j];
        rep(i, w) rep(j, w) d[i][j] += e[i][j];
    }
    { // green
        vector e(w, vector<ll>(w));
        rep(i, n) rep(j, n)
        {
            e[i + 2][j + n * 2 - 1] += c[i][j];
            e[i + n * 2][j + 1] -= c[i][j];
        }
        rep(i, w - 1) rep(j, w - 1) e[i + 1][j] += e[i][j + 1];
        rep(i, w) rep(j, w) d[i][j] += e[i][j];
    }
    { // red
        rep(i, n) rep(j, n)
        {
            d[i + 1][j + 1] += c[i][j] * ll(n - 1);
            d[i + 1][j + n * 2] -= c[i][j] * ll(n - 1);
            d[i + n * 2][j + 1] -= c[i][j] * ll(n - 1);
            d[i + n * 2][j + n * 2] += c[i][j] * ll(n - 1);
        }
    }

    rep(i, w - 1) rep(j, w - 1) d[i + 1][j] += d[i][j];
    rep(i, w - 1) rep(j, w - 1) d[i][j + 1] += d[i][j];

    ll ans = 0;
    rep(i, n) rep(j, n)
    {
        ans ^= d[n + i][n + j] + n * i + j;
    }
    cout << ans << endl;
    return 0;
}