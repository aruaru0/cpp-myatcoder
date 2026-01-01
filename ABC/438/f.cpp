#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> pa(n);
    vector<int> t(n);
    auto dfs = [&](auto dfs, int v, int p = -1) -> int
    {
        pa[v] = p;
        t[v] = 1;
        for (int u : to[v])
            if (u != p)
            {
                t[v] += dfs(dfs, u, v);
            }
        return t[v];
    };
    dfs(dfs, 0);

    ll ans = 0;
    {
        auto f = [](ll x)
        { return x * (x + 1) / 2; };
        ans = f(n);
        for (int v : to[0])
            ans -= f(t[v]);
    }

    vector<bool> used(n);
    used[0] = true;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (!used[i])
        {
            int v = i, pre = -1;
            while (!used[v])
            {
                used[v] = true;
                pre = v;
                v = pa[v];
            }
            if (v == 0)
                t[0] -= t[pre];
            if (l == v)
                l = i;
            else if (r == v)
                r = i;
            else
                break;
        }

        ans += (ll)t[l] * t[r];
    }
    cout << ans << endl;
    return 0;
}