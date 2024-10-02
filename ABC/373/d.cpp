#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<P>> node(n);

    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        node[u].emplace_back(v, w);
        node[v].emplace_back(u, -w);
    }

    vector<ll> dist(n, 0);
    vector<bool> used(n, false);

    auto dfs = [&](auto dfs, int cur, ll cnt) -> void
    {
        used[cur] = true;
        dist[cur] = cnt;
        for (auto [next, w] : node[cur])
        {
            if (used[next])
                continue;
            dfs(dfs, next, dist[cur] + w);
        }
    };

    rep(i, n)
    {
        if (used[i])
            continue;

        dfs(dfs, i, 0);
    }

    for (auto e : dist)
    {
        cout << e << " ";
    }
    cout << endl;
}