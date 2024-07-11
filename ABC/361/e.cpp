#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct Edge
{
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main()
{
    int n;
    cin >> n;
    ll tot = 0;
    vector<vector<Edge>> node(n);
    rep(i, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        node[a].emplace_back(b, c);
        node[b].emplace_back(a, c);
        tot += c * 2;
    }

    // auto dfs = [&](auto f, int v, ll d = 0, int p = -1) -> pair<ll, int>
    // {
    //     auto res = make_pair(d, v);
    //     for (auto e : g[v])
    //     {
    //         if (e.to == p)
    //             continue;
    //         res = max(res, f(f, e.to, d + e.cost, v));
    //     }
    //     return res;
    // };
    const long long inf = 1e18;
    auto dijkstra = [&](int s, int &pos)
    {
        vector<ll> dist(n, inf);
        dist[s] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, s);
        while (!pq.empty())
        {
            auto [d, v] = pq.top();
            pq.pop();
            if (d > dist[v])
                continue;
            for (auto e : node[v])
            {
                if (dist[e.to] > dist[v] + e.cost)
                {
                    dist[e.to] = dist[v] + e.cost;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        ll ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (ret < dist[i])
            {
                ret = max(ret, dist[i]);
                pos = i;
            }
        }
        return ret;
    };
    int pos = 0;
    dijkstra(0, pos);
    ll dist = dijkstra(pos, pos);
    tot -= dist;
    std::cout << tot << endl;
    return 0;
}