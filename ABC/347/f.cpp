#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmax(ll &a, ll b) { a = max(a, b); }

// 解説のコードを写経した
int main()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector s(n + 1, vector<ll>(n + 1));
    rep(i, n) rep(j, n) s[i + 1][j + 1] = a[i][j];
    rep(i, n) rep(j, n) s[i + 1][j + 1] += s[i + 1][j];
    rep(i, n) rep(j, n) s[i + 1][j + 1] += s[i][j + 1];

    int w = n - m + 1;
    vector d(w, vector<ll>(w));
    rep(i, w) rep(j, w)
    {
        ll now = s[i + m][j + m];
        now -= s[i][j + m];
        now -= s[i + m][j];
        now += s[i][j];
        d[i][j] = now;
    }

    ll ans = 0;
    rep(hi, 2)
    {
        rep(wi, 2)
        {
            vector<ll> col(w);
            rep(j, w) rep(i, w) chmax(col[j], d[i][j]);

            vector ru = d, rd = d;
            rep(i, w) for (int j = w - 1; j >= 0; j--)
            {
                if (i)
                    chmax(ru[i][j], ru[i - 1][j]);
                if (j + 1 < w)
                    chmax(ru[i][j], ru[i][j + 1]);
            }
            for (int i = w - 1; i >= 0; i--)
            {
                for (int j = w - 1; j >= 0; j--)
                {
                    if (i + 1 < w)
                        chmax(rd[i][j], rd[i + 1][j]);
                    if (j + 1 < w)
                        chmax(rd[i][j], rd[i][j + 1]);
                }
            }

            ll lmax = 0;
            rep(j, w - m)
            {
                chmax(lmax, col[j]);
                { // type A
                    ll mmax = 0;
                    for (int nj = j + m; nj < w; nj++)
                    {
                        chmax(mmax, col[nj]);
                        int mj = nj + m;
                        if (mj >= w)
                            break;
                        ll rmax = ru[w - 1][mj];
                        chmax(ans, lmax + mmax + rmax);
                    }
                }
                { // type B
                    int nj = j + m;
                    rep(i, w - m)
                    {
                        ll umax = ru[i][nj];
                        ll dmax = rd[i + m][nj];
                        chmax(ans, lmax + umax + dmax);
                    }
                }
            }
            rep(i, w) reverse(d[i].begin(), d[i].end());
        }
        vector old = d;
        rep(i, w) rep(j, w) d[i][j] = old[j][i];
    }

    cout << ans << endl;
    return 0;
}