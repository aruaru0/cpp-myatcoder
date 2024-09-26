#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;

    auto uf = atcoder::dsu(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++)
    {
        g[i].push_back(i);
    }

    for (int qi = 0; qi < q; qi++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (uf.same(u, v))
            {
                continue;
            }
            auto x = uf.leader(u), y = uf.leader(v);
            vector<int> tmp;
            for (auto e : g[x])
                tmp.push_back(e);
            for (auto e : g[y])
                tmp.push_back(e);

            // tmpを大きい順にソート
            // sort(tmp.begin(), tmp.end(), greater<>());
            sort(tmp.begin(), tmp.end(), [&](int a, int b)
                 { return a > b; });
            if (tmp.size() > 10)
                tmp.resize(10);

            g[x].clear();
            g[y].clear();
            uf.merge(u, v);
            auto l = uf.leader(u);

            g[l] = tmp;
            // for (auto e : g)
            // {
            //     cout << '[';
            //     for (auto v : e)
            //     {
            //         cout << v << " ";
            //     }
            //     cout << ']';
            // }
            // cout << endl;
        }
        else
        {
            int u, k;
            cin >> u >> k;
            u--;
            auto l = uf.leader(u);
            if (g[l].size() < k)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << g[l][k - 1] + 1 << endl;
            }
        }
    }

    return 0;
}
