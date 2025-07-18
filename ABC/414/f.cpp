#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> edges;
    vector<vector<pair<int, int>>> g(n); // to, edge_id
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.emplace_back(a, b);
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, n - 1 + i);
    }

    const int INF = 1001001001;
    vector dist((n - 1) * 2, vector<int>(k, INF));
    vector cnt(n, vector<int>(k));
    queue<pair<int, int>> q;
    auto push = [&](int ei, int d)
    {
        int w = d % k;
        if (dist[ei][w] != INF)
            return;
        dist[ei][w] = d;
        q.emplace(ei, d);
    };
    for (auto [to, ei] : g[0])
        push(ei, 1);
    while (q.size())
    {
        auto [ei, d] = q.front();
        q.pop();
        int v;
        {
            auto [a, b] = edges[ei % (n - 1)];
            if (ei < n - 1)
                v = b;
            else
                v = a;
        }
        if ((++cnt[v][d % k]) <= 2)
        {
            for (auto [to, ej] : g[v])
            {
                if (d % k != 0 && ei % (n - 1) == ej % (n - 1))
                    continue;
                push(ej, d + 1);
            }
        }
    }

    vector<int> ans(n, INF);
    rep(i, (n - 1) * 2)
    {
        auto [a, b] = edges[i % (n - 1)];
        if (i >= n - 1)
            swap(a, b);
        ans[b] = min(ans[b], dist[i][0]);
    }
    for (int i = 1; i < n; i++)
    {
        if (ans[i] == INF)
            ans[i] = -1;
        else
            ans[i] /= k;
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}