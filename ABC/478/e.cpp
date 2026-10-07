#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> nes;
    scc_graph g(n);
    rep(qi, q)
    {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
        if (t == 1)
            nes.emplace_back(a, b);
    }
    auto ds = g.scc();
    vector<int> ans(n);
    rep(i, ds.size())
    {
        for (int v : ds[i])
            ans[v] = i + 1;
    }
    for (auto [a, b] : nes)
        if (ans[a] == ans[b])
        {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    for (int x : ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}