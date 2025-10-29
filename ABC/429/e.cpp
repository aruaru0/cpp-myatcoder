#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    // グラフ作成
    vector<vector<int>> to(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    string s;
    cin >> s;

    const int INF = 1001001001;
    using P = pair<int, int>;
    vector<vector<P>> dist(n);

    // cur, start, dist
    queue<tuple<int, int, int>> q;

    // キューへ追加処理
    auto push = [&](int v, int sv, int d)
    {
        if (dist[v].size() >= 2)
            return;
        for (auto p : dist[v])
            if (p.second == sv)
                return;
        dist[v].emplace_back(d, sv);
        q.emplace(v, sv, d);
    };

    // キューに登録
    rep(v, n) if (s[v] == 'S') push(v, v, 0);

    while (q.size())
    {
        auto [v, sv, d] = q.front();
        q.pop();
        for (int u : to[v])
            push(u, sv, d + 1);
    }

    rep(v, n) if (s[v] == 'D')
    {
        int ans = dist[v][0].first + dist[v][1].first;
        cout << ans << '\n';
    }
    return 0;
}