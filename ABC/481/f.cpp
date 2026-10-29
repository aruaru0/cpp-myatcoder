#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

int main()
{
    int n, m;
    cin >> n >> m;
    using P = pair<int, int>;
    vector<vector<P>> g(n);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c);
    }

    const int INF = 1001001001;
    vector<P> dist(n, P(INF, 0));
    vector<mint> ans(n);
    using Q = pair<P, int>;
    priority_queue<Q, vector<Q>, greater<Q>> q;
    auto push = [&](int v, int pre, P p)
    {
        if (dist[v] <= p)
            return;
        dist[v] = p;
        if (pre != -1)
            ans[v] = ans[pre] * 10 + p.second;
        else
            ans[v] = p.second;
        q.emplace(p, v);
    };
    push(0, -1, P(-1, 0));
    vector<P> ps(1, P(-1, -1));
    while (q.size())
    {
        auto [p, v] = q.top();
        q.pop();
        if (dist[v] != p)
            continue;
        if (ps.back() != p)
            ps.push_back(p);
        for (auto [u, c] : g[v])
        {
            push(u, v, P(ps.size(), c));
        }
    }

    rep(i, n) if (i) cout << ans[i].val() << '\n';
    return 0;
}