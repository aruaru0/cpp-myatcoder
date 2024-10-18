#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, q;

    cin >> n >> m >> q;

    vector<int> a(m), b(m), c(m);

    rep(i, m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    vector<int> t(q), x(q), y(q);
    map<int, bool> mp;
    rep(i, q)
    {
        cin >> t[i];
        if (t[i] == 1)
            cin >> x[i];
        else
            cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;

        if (t[i] == 1)
        {
            mp[x[i]] = true;
        }
    }

    const ll inf = 1e18;
    vector<vector<ll>> d(n, vector<ll>(n, inf));
    rep(i, n) d[i][i] = 0;

    rep(i, m)
    {
        if (mp[i])
            continue;
        d[a[i]][b[i]] = c[i];
        d[b[i]][a[i]] = c[i];
    }

    rep(k, n) rep(i, n) rep(j, n)
    {
        if (d[i][j] > d[i][k] + d[k][j])
        {
            d[i][j] = d[i][k] + d[k][j];
        }
    }

    // rep(i, n)
    // {
    //     rep(j, n)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<ll> ans;
    for (int qi = q - 1; qi >= 0; qi--)
    {
        if (t[qi] == 1)
        {
            auto idx = x[qi];
            auto u = a[idx], v = b[idx], w = c[idx];
            rep(i, n) rep(j, n)
            {
                if (d[i][j] > d[i][u] + w + d[v][j])
                {
                    d[i][j] = d[i][u] + w + d[v][j];
                }
                if (d[i][j] > d[i][v] + w + d[u][j])
                {
                    d[i][j] = d[i][v] + w + d[u][j];
                }
            }

            // cout << "add " << idx << endl;
            // rep(i, n)
            // {
            //     rep(j, n)
            //     {
            //         cout << d[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }
        else
        {
            auto u = x[qi], v = y[qi];
            ans.push_back(d[u][v]);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] == inf)
        {
            ans[i] = -1;
        }
        cout << ans[i] << endl;
    }

    return 0;
}
