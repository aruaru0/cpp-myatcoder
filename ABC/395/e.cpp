#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<P>> a(n * 2);

    rep(i, n)
    {
        a[i].push_back(P(i + n, x));
        a[i + n].push_back(P(i, x));
    }

    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(P(v, 1));
        a[v + n].push_back(P(u + n, 1));
    }

    const ll inf = 1e18;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(n * 2, inf);
    pq.push(P(0, 0));
    dist[0] = 0;

    while (!pq.empty())
    {
        auto [cost, cur] = pq.top();
        pq.pop();

        // cout << cost << " " << cur << endl;

        if (dist[cur] < cost)
            continue;
        for (auto [e_to, e_cost] : a[cur])
        {
            if (dist[e_to] > dist[cur] + e_cost)
            {
                dist[e_to] = dist[cur] + e_cost;
                pq.push(P(dist[e_to], e_to));
            }
        }
    }

    ll ans = min(dist[n - 1], dist[2 * n - 1]);

    cout << ans << endl;

    return 0;
}