#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ull = unsigned long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    auto enumPath = [&]()
    {
        vector<vector<ull>> res(n);
        auto dfs = [&](auto dfs, int i, int j, ull x)
        {
            if (i + j == n - 1)
            {
                res[i].push_back(x);
                return;
            }
            x = x * 10 + a[i][j];
            dfs(dfs, i + 1, j, x);
            dfs(dfs, i, j + 1, x);
        };
        dfs(dfs, 0, 0, 0);
        return res;
    };

    auto ss = enumPath();
    rep(i, n) reverse(a[i].begin(), a[i].end());
    reverse(a.begin(), a.end());
    auto ts = enumPath();
    reverse(ts.begin(), ts.end());

    ull ans = 0;
    auto f = [&](vector<ull> &s, vector<ull> &t, int d)
    {
        ull ten = 1;
        rep(i, n) ten = ten * 10 % m;
        for (ull &x : s)
            x = (x % m * ten) % m;

        for (ull &x : t)
        {
            ull y = x;
            x = d;
            rep(i, n - 1)
            {
                x = (x * 10 + y % 10) % m;
                y /= 10;
            }
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // for (ull x : s) cerr << x << ' '; cerr << endl;
        // for (ull x : t) cerr << x << ' '; cerr << endl;
        for (ull x : s)
        {
            int i = lower_bound(t.begin(), t.end(), m - x) - t.begin();
            if (i)
                ans = max(ans, x + t[i - 1]);
            ans = max(ans, (x + t.back()) % m);
        }
    };
    rep(i, n) f(ss[i], ts[i], a[n - 1 - i][i]);
    cout << ans << endl;
    return 0;
}