#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

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

    int ans = -1;
    auto dfs = [&](auto dfs, int v, int p = -1) -> int
    {
        int res = 1;
        vector<int> d;
        for (int u : to[v])
        {
            if (u == p)
                continue;
            d.push_back(dfs(dfs, u, v));
        }
        sort(d.rbegin(), d.rend());
        if (d.size() >= 3)
        {
            res = d[0] + d[1] + d[2] + 1;
            if (d.size() >= 4)
            {
                ans = max(ans, res + d[3]);
            }
        }
        if (d.size() >= 1)
        {
            if (d[0] + 1 > 2)
                ans = max(ans, d[0] + 1);
        }
        return res;
    };
    dfs(dfs, 0);
    cout << ans << endl;
    return 0;
}