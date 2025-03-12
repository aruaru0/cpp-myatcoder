#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<P>> node(n);
    rep(i, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        node[u].push_back({v, w});
        node[v].push_back({u, w});
    }

    ll ans = 1LL << 61;
    vector<bool> used(n);

    auto dfs = [&](auto dfs, int cur, ll score)
    {
        if (cur == n - 1)
        {
            ans = min(ans, score);
            return;
        }
        used[cur] = true;
        for (auto [to, cost] : node[cur])
        {
            if (used[to])
                continue;
            dfs(dfs, to, score ^ cost);
        }

        used[cur] = false;
    };

    dfs(dfs, 0, 0);
    cout << ans << endl;

    return 0;
}
