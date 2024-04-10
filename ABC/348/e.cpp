#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> c(n);
    ll tot = 0;
    rep(i, n)
    {
        cin >> c[i];
        tot += c[i];
    }

    int x = -1;
    auto dfs = [&](auto dfs, int cur, int prev = -1) -> ll
    {
        ll res = c[cur];
        ll max_leaf = 0;
        for (int e : to[cur])
        {
            if (e == prev)
                continue;
            ll ret = dfs(dfs, e, cur);
            max_leaf = max(max_leaf, ret);
            res += ret;
        }
        ll mx = max(max_leaf, tot - res);
        if (mx * 2 <= tot)
        {
            x = cur;
        }
        return res;
    };

    dfs(dfs, 0);

    ll ans = 0;
    auto dfs2 = [&](auto dfs2, int cur, int prev = -1, int dist = 0) -> void
    {
        ans += (ll)dist * (ll)c[cur];
        for (int e : to[cur])
        {
            if (e == prev)
                continue;
            dfs2(dfs2, e, cur, dist + 1);
        }
    };

    dfs2(dfs2, x);
    cout << ans << endl;
}