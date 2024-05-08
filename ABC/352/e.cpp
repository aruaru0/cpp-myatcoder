#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

typedef struct
{
    int c;
    vector<int> v;
} Edges;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edges> edges(m);
    rep(i, m)
    {
        int k, c;
        cin >> k >> c;
        edges[i].c = c;
        edges[i].v = vector<int>(k);
        rep(j, k)
        {
            int v;
            cin >> v;
            edges[i].v[j] = v - 1;
        }
    }

    sort(edges.begin(), edges.end(), [](Edges a, Edges b)
         { return a.c < b.c; });

    // for (auto e : edges)
    // {
    //     cout << e.c << endl;
    //     for (auto v : e.v)
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    auto uf = dsu(n);
    ll ans = 0;

    for (auto e : edges)
    {
        auto cur = e.v[0];
        for (auto v : e.v)
        {
            if (!uf.same(cur, v))
            {
                uf.merge(cur, v);
                ans += e.c;
            }
        }
    }

    if (uf.size(0) != n)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}
