#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    scc_graph g(n);
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
        g.add_edge(i, a[i]);
    }

    vector<ll> dist(n, 0);
    vector<bool> used(n, false);
    queue<int> q;

    auto scc = g.scc();
    reverse(scc.begin(), scc.end());

    for (auto c : scc)
    {
        if (c.size() > 1 || a[c[0]] == c[0])
        {
            for (auto v : c)
            {
                dist[v] = c.size();
                used[v] = true;
            }
        }
        else
        {
            dist[c[0]] = dist[a[c[0]]] + 1;
        }
    }

    ll ans = 0;
    rep(i, n)
    {
        ans += dist[i];
    }
    cout << ans << endl;
}
