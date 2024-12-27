#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> deg(n);
    rep(i, n) deg[i] = to[i].size();

    int ans = n;
    rep(v, n)
    {
        vector<int> d;
        for (int u : to[v])
            d.push_back(deg[u]);
        sort(d.rbegin(), d.rend());
        rep(i, deg[v])
        {
            int now = d[i] * (i + 1) + 1;
            ans = min(ans, n - now);
        }
    }

    cout << ans << endl;
    return 0;
}