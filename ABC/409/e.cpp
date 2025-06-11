#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    vector<vector<P>> node(n);
    rep(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        node[u].push_back(P(v, w));
        node[v].push_back(P(u, w));
    }

    vector<int> cnt(n);
    deque<int> q;
    rep(i, n)
    {
        cnt[i] = node[i].size();
        if (cnt[i] == 1)
        {
            q.push_back(i);
        }
    }

    vector<bool> used(n);
    ll ans = 0;

    while (q.size())
    {
        int cur = q.front();
        q.pop_front();
        used[cur] = true;
        for (auto p : node[cur])
        {
            if (used[p.first])
                continue;
            ans += (ll)p.second * abs(x[cur]);
            x[p.first] += x[cur];
            cnt[p.first]--;
            if (cnt[p.first] == 1)
            {
                q.push_back(p.first);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
