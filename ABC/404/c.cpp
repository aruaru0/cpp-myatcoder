#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    rep(i, n)
    {
        if (node[i].size() != 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    bool ok = true;
    deque<int> q;
    q.push_back(0);
    vector<bool> used(n);
    used[0] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (int e : node[v])
        {
            if (used[e])
            {
                continue;
            }
            q.push_back(e);
            used[e] = true;
        }
    }

    rep(i, n)
    {
        if (!used[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
