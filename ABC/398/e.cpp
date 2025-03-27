#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> node(N);
    set<pii> m;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        node[u].push_back(v);
        node[v].push_back(u);
        m.insert({u, v});
    }

    vector<int> p[2];
    function<void(int, int, int)> dfs = [&](int cur, int pre, int flg)
    {
        p[flg].push_back(cur);
        for (int e : node[cur])
        {
            if (e == pre)
                continue;
            dfs(e, cur, 1 ^ flg);
        }
    };

    dfs(0, -1, 0);

    set<pii> rest;
    for (int x : p[0])
    {
        for (int y : p[1])
        {
            int u = x, v = y;
            if (u > v)
                swap(u, v);
            if (m.find({u, v}) == m.end())
            {
                rest.insert({u, v});
            }
        }
    }

    int turn = 0;
    if (rest.size() % 2 == 1)
    {
        cout << "First" << endl;
        turn = 0;
    }
    else
    {
        cout << "Second" << endl;
        turn = 1;
    }

    while (true)
    {
        if (turn == 0)
        {
            if (rest.empty())
                return 0;
            auto it = rest.begin();
            int u = it->first, v = it->second;
            cout << u + 1 << " " << v + 1 << endl;
            rest.erase(it);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            if (u == -1)
                return 0;
            if (u > v)
                swap(u, v);
            rest.erase({u - 1, v - 1});
        }
        turn ^= 1;
    }
    return 0;
}
