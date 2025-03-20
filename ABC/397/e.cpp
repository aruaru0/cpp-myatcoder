#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    int nk = n * k;
    vector<vector<int>> to(nk);
    rep(i, nk - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    bool ok = true;
    auto dfs = [&](auto dfs, int v, int p = -1) -> int
    {
        int res = 1;
        int deg = 0;
        for (int u : to[v])
            if (u != p)
            {
                int sz = dfs(dfs, u, v);
                if (sz % k)
                    deg++;
                res += sz;
            }
        if (res % k)
            deg++;
        if (deg > 2)
            ok = false;
        return res;
    };
    dfs(dfs, 0);
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}