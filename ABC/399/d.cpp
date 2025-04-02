#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n;
    cin >> n;
    int n2 = n * 2;
    vector<int> a(n2);
    rep(i, n2)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> pos(n);
    rep(i, n2) pos[a[i]].push_back(i);

    using P = pair<int, int>;
    set<P> cand;
    rep(i, n2 - 1)
    {
        int x = a[i], y = a[i + 1];
        if (x > y)
            swap(x, y);
        if (x == y)
            continue;
        cand.emplace(x, y);
    }

    int ans = 0;
    for (auto [x, y] : cand)
    {
        int xl = pos[x][0], xr = pos[x][1];
        int yl = pos[y][0], yr = pos[y][1];
        if (xl + 1 == xr)
            continue;
        if (yl + 1 == yr)
            continue;
        if (abs(xl - yl) == 1 && abs(xr - yr) == 1)
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T)
    {
        solve();
    }
    return 0;
}