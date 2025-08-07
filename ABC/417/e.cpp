#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n++;
    vector<vector<int>> to(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<bool> used(n);
    vector<int> ans = {x};
    used[x] = true;
    while (x != y)
    {
        vector<bool> reach(n);
        queue<int> q;
        reach[y] = true;
        q.push(y);
        while (q.size())
        {
            int v = q.front();
            q.pop();
            for (int u : to[v])
            {
                if (used[u])
                    continue;
                if (reach[u])
                    continue;
                reach[u] = true;
                q.push(u);
            }
        }
        int nx = n;
        for (int v : to[x])
        {
            if (used[v])
                continue;
            if (!reach[v])
                continue;
            nx = min(nx, v);
        }
        x = nx;
        used[x] = true;
        ans.push_back(x);
    }

    rep(i, ans.size()) cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}