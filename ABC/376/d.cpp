#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        node[a].push_back(b);
    }

    queue<P> q;
    q.push({0, 0});

    vector<int> dist(n, inf);

    while (!q.empty())
    {
        P p = q.front();
        auto cur = p.first;
        auto cost = p.second;
        q.pop();
        for (int u : node[cur])
        {
            if (dist[u] == inf)
            {
                dist[u] = cost + 1;
                q.push({u, dist[u]});
            }
        }
    }

    if (dist[0] == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[0] << endl;
    }

    return 0;
}
