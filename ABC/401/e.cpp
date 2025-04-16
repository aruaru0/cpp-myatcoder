#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> node(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        node[u].push_back(v);
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    map<int, int64_t> g;
    atcoder::dsu uf(n);

    rep(i, n)
    {
        for (auto e : node[i])
        {
            pq.push({e, i});
            g[e]++;
        }
        while (pq.size() && pq.top().first <= i)
        {
            auto [x, from] = pq.top();
            pq.pop();
            uf.merge(from, x);
            g[x]--;
            if (g[x] == 0)
            {
                g.erase(x);
            }
        }
        if (uf.size(i) == i + 1)
        {
            cout << g.size() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
