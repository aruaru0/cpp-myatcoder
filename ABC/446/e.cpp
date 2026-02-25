#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int m, a, b;
    cin >> m >> a >> b;
    int n = m * m;
    vector<vector<int>> to(n);
    rep(i, m) rep(j, m)
    {
        int k = (j * a + i * b) % m;
        int v = i * m + j, u = j * m + k;
        to[u].push_back(v);
    }

    vector<bool> used(n);
    queue<int> q;
    auto push = [&](int v)
    {
        if (used[v])
            return;
        used[v] = true;
        q.push(v);
    };

    rep(i, m)
    {
        push(i);
        push(i * m);
    }

    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (int u : to[v])
            push(u);
    }

    int ans = 0;
    rep(i, n) if (!used[i]) ans++;
    cout << ans << endl;
    return 0;
}