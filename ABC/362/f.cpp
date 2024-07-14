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

    int centroid = 0;
    vector<int> sz(n);
    auto dfs = [&](auto dfs, int v, int p = -1) -> int
    {
        int mx = 0;
        sz[v] = 1;
        for (int u : to[v])
        {
            if (u == p)
                continue;
            sz[v] += dfs(dfs, u, v);
            mx = max(mx, sz[u]);
        }
        mx = max(mx, n - sz[v]);
        if (mx * 2 <= n)
            centroid = v;
        return sz[v];
    };
    dfs(dfs, 0);

    vector<int> vs;
    auto dfs2 = [&](auto dfs2, int v, int p = -1) -> void
    {
        for (int u : to[v])
        {
            if (u == p)
                continue;
            dfs2(dfs2, u, v);
        }
        vs.push_back(v);
    };
    dfs2(dfs2, centroid);
    if (n % 2 == 1)
        vs.pop_back();

    rep(i, n / 2)
    {
        int a = vs[i], b = vs[i + n / 2];
        printf("%d %d\n", a + 1, b + 1);
    }
    return 0;
}