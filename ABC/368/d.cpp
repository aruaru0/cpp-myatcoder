#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> node(n, vector<int>());
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    set<int> v;
    rep(i, k)
    {
        int a;
        cin >> a;
        a--;
        v.insert(a);
    }

    queue<int> q;
    vector<int> cnt(n, 0);
    rep(i, n)
    {
        cnt[i] = node[i].size();
        if (cnt[i] == 1)
        {
            q.push(i);
        }
    }

    int ans = n;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (v.count(cur))
        {
            continue;
        }
        ans--;
        for (auto e : node[cur])
        {
            if (e == cur)
            {
                continue;
            }
            if (v.count(e))
            {
                continue;
            }
            cnt[e]--;
            if (cnt[e] == 1)
            {
                q.push(e);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
