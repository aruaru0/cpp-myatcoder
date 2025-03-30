#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> node(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    vector<bool> used(n);

    int cnt = 0;
    auto dfs = [&](auto dfs, int cur) -> void
    {
        used[cur] = true;
        for (auto e : node[cur])
        {
            if (used[e])
            {
                continue;
            }
            cnt++;
            dfs(dfs, e);
        }
    };

    rep(i, n)
    {
        if (!used[i])
        {
            dfs(dfs, i);
        }
    }

    cout << m - cnt << endl;

    return 0;
}
