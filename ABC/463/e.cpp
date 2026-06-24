#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

struct edge
{
    ll cost;
    int to;
};

int main()
{
    int n, m, y;
    cin >> n >> m >> y;

    vector<vector<edge>> node(n + 1);
    rep(i, m)
    {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        node[u].push_back({t, v});
        node[v].push_back({t, u});
    }

    int warp = n;
    rep(i, n)
    {
        int x;
        cin >> x;
        node[i].push_back({x + y, warp});
        node[warp].push_back({x, i});
    }

    // rep(i, n + 1)
    // {
    //     cout << i << ":" << endl
    //          << "   ";
    //     for (auto [c, to] : node[i])
    //     {
    //         cout << to << ":" << c << ", ";
    //     }
    //     cout << endl;
    // }

    const ll inf = 1e18;
    vector<ll> dist(n + 1, inf);
    dist[0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while (pq.size() != 0)
    {
        auto [cost, from] = pq.top();
        pq.pop();
        if (dist[from] < cost)
        {
            continue;
        }
        for (auto [c, to] : node[from])
        {
            if (dist[to] > dist[from] + c)
            {
                dist[to] = dist[from] + c;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
