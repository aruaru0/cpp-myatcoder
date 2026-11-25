#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<P>> g(n);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        g[a].emplace_back(b, c);
    }

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    vector<int> color(n, -1);
    queue<tuple<int, int, int>> q;
    dist[0] = 0;
    color[0] = INF;
    q.emplace(0, 0, -2);

    while (q.size())
    {
        auto [d, v, pc] = q.front();
        q.pop();
        for (auto [u, c] : g[v])
        {
            if (pc == c)
                continue;
            if (color[u] == INF)
                continue;
            if (color[u] == c)
                continue;
            if (color[u] == -1)
                color[u] = c, dist[u] = d + 1;
            else
                color[u] = INF;
            q.emplace(d + 1, u, c);
        }
    }
    int ans = dist[n - 1];
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}