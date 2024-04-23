#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> edge(n);
    dsu uf(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a]++;
        uf.merge(a, b);
    }

    ll ans = 0;
    for (auto e : uf.groups())
    {
        ll tot = 0;
        for (auto v : e)
        {
            tot += edge[v];
        }
        ll size = e.size();
        ans += size * (size - 1) / 2 - tot;
    }

    cout << ans << endl;
}