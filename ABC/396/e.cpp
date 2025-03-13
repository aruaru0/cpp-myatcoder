#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    bool ok = true;
    vector<int> ans(n);
    rep(k, 30)
    {
        vector<int> col(n, -1);
        rep(sv, n) if (col[sv] == -1)
        {
            vector<vector<int>> vs(2);
            auto dfs = [&](auto dfs, int v, int c) -> void
            {
                if (col[v] != -1)
                {
                    if (col[v] != c)
                        ok = false;
                    return;
                }
                col[v] = c;
                vs[c].push_back(v);
                for (auto [to, z] : g[v])
                {
                    dfs(dfs, to, c ^ (z >> k & 1));
                }
            };
            dfs(dfs, sv, 0);
            if (vs[0].size() < vs[1].size())
                swap(vs[0], vs[1]);
            for (int v : vs[1])
                ans[v] |= 1 << k;
        }
    }
    if (!ok)
    {
        cout << -1 << endl;
        return 0;
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}