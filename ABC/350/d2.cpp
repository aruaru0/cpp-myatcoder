#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    vector<bool> used(n);
    // 接続されているノードの数を数える
    auto dfs = [&](auto dfs, int cur) -> int
    {
        used[cur] = true;
        int ret = 1;
        for (auto e : node[cur])
        {
            if (used[e])
                continue;
            ret += dfs(dfs, e);
        }
        return ret;
    };

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        ll s = dfs(dfs, i);
        ans += s * (s - 1) / 2; // 完全グラフの場合の連結数を加算
    }
    cout << ans - m << endl;
}