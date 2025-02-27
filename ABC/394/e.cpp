#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<string> c(n);
    rep(i, n) cin >> c[i];

    const int INF = 1001001001;
    vector dist(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    auto push = [&](int s, int t, int d)
    {
        if (dist[s][t] != INF)
            return;
        dist[s][t] = d;
        q.emplace(s, t);
    };
    rep(i, n) push(i, i, 0);
    rep(i, n) rep(j, n) if (c[i][j] != '-') push(i, j, 1);
    while (q.size())
    {
        auto [s, t] = q.front();
        q.pop();
        rep(ns, n) rep(nt, n)
        {
            if (c[ns][s] == '-')
                continue;
            if (c[t][nt] == '-')
                continue;
            if (c[ns][s] != c[t][nt])
                continue;
            push(ns, nt, dist[s][t] + 2);
        }
    }

    rep(i, n)
    {
        rep(j, n)
        {
            int ans = dist[i][j];
            if (ans == INF)
                ans = -1;
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}