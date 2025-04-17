#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    auto readTree = [&]()
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

        using P = pair<int, int>;
        vector<int> dist(n, 0);
        auto dfs = [&](auto dfs, int v, int dep = 0, int p = -1) -> P
        {
            dist[v] = max(dist[v], dep);
            P res(dep, v);
            for (int u : to[v])
                if (u != p)
                {
                    res = max(res, dfs(dfs, u, dep + 1, v));
                }
            return res;
        };
        int a = dfs(dfs, 0).second;
        auto [d, b] = dfs(dfs, a);
        dfs(dfs, b);

        vector<ll> c(n);
        rep(i, n) c[dist[i]]++;

        return make_pair(d, c);
    };

    auto [da, a] = readTree();
    auto [db, b] = readTree();
    int d = max(da, db);

    auto c = convolution_ll(a, b);
    ll ans = 0;
    rep(i, c.size())
    {
        ans += max(i + 1, d) * c[i];
    }
    cout << ans << endl;
    return 0;
}