#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, int>;

const ll INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<P>> node(n);
    rep(i, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        node[u].push_back(P(v, c));
        node[v].push_back(P(u, c));
    }

    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[0] = a[0];
    que.push(P{a[0], 0});
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        ll c = p.first;
        int cur = p.second;
        if (dist[cur] < c)
            continue;
        for (auto e : node[cur])
        {
            if (dist[e.first] > (ll)c + e.second + a[e.first])
            {
                dist[e.first] = (ll)c + e.second + a[e.first];
                que.push(P{dist[e.first], e.first});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}