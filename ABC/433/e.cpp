#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<int> x(h), y(w);
    rep(i, h) cin >> x[i];
    rep(i, w) cin >> y[i];

    map<int, int> rid, cid;
    rep(i, h) rid[x[i]] = i;
    rep(i, w) cid[y[i]] = i;

    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());

    vector a(h, vector<int>(w));
    {
        int xi = 0, yi = 0;
        vector<pair<int, int>> cand;
        for (int v = h * w; v >= 1; v--)
        {
            if (xi < h && x[xi] == v)
            {
                rep(j, yi) cand.emplace_back(xi, j);
                xi++;
            }
            if (yi < w && y[yi] == v)
            {
                rep(i, xi) cand.emplace_back(i, yi);
                yi++;
            }
            if (cand.size() == 0)
            {
                cout << "No\n";
                return;
            }
            auto [i, j] = cand.back();
            cand.pop_back();
            a[i][j] = v;
        }
    }

    vector ans(h, vector<int>(w));
    rep(i, h) rep(j, w) ans[rid[x[i]]][cid[y[j]]] = a[i][j];
    cout << "Yes\n";
    rep(i, h)
    {
        rep(j, w) cout << ans[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}