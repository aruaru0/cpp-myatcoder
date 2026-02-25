#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    vector<vector<int>> ot(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        ot[b].push_back(a);
    }

    vector<bool> mark(n);
    int markCnt = 0;
    vector<bool> adj(n);
    int adjCnt = 0;
    queue<int> q;
    auto reach = [&](int v)
    {
        if (mark[v])
            return;
        mark[v] = true;
        markCnt++;
        q.push(v);
    };
    rep(k, n)
    {
        if (adj[k])
            adjCnt--;
        if (adj[k] || k == 0)
            reach(k);
        while (q.size())
        {
            int v = q.front();
            q.pop();
            for (int u : to[v])
            {
                if (u <= k)
                    reach(u);
                else
                {
                    if (!adj[u])
                        adj[u] = true, adjCnt++;
                }
            }
        }
        if (k + 1 == markCnt)
        {
            cout << adjCnt << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}