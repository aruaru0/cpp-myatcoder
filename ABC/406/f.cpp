#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    vector<pair<int, int>> es;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        es.emplace_back(a, b);
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> in(n), out(n);
    int vid = 0;
    auto dfs = [&](auto dfs, int v, int p = -1) -> void
    {
        in[v] = vid++;
        for (int u : to[v])
            if (u != p)
            {
                dfs(dfs, u, v);
            }
        out[v] = vid;
    };
    dfs(dfs, 0);

    fenwick_tree<int> t(n);
    rep(i, n) t.add(i, 1);

    int q;
    cin >> q;
    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int v, w;
            cin >> v >> w;
            v--;
            t.add(in[v], w);
        }
        else
        {
            int ei;
            cin >> ei;
            ei--;
            auto [a, b] = es[ei];
            if (in[a] < in[b])
                swap(a, b);
            int as = t.sum(in[a], out[a]);
            int bs = t.sum(0, n) - as;
            cout << abs(as - bs) << '\n';
        }
    }
    return 0;
}