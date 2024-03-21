#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct Edge
{
    int to, id;
    Edge(int to, int id) : to(to), id(id) {}
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> node(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].emplace_back(b, i + 1);
        node[b].emplace_back(a, i + 1);
    }

    vector<bool> used(n);
    vector<int> ans;
    auto dfs = [&](auto dfs, int v, int pid = -1) -> int
    {
        int now = 0;
        used[v] = true;
        for (Edge e : node[v])
        {
            if (used[e.to] == true)
                continue;
            // 使われているエッジの数が奇数か偶数かをチェック
            now ^= dfs(dfs, e.to, e.id);
        }
        // ｋ＝０でなければ、点灯させる必要がある
        int target = k == 0 ? 0 : 1;
        int res = 0;
        // 現状点灯していなくてつけなければならない場合、つまり辺を使う必要がある場合（根ではない場合）
        if (now != target && pid != -1)
        {
            now ^= 1;
            res = 1;
            ans.push_back(pid);
        }
        k -= now;
        return res;
    };

    rep(i, n)
    {
        if (used[i] == false)
        {
            dfs(dfs, i);
        }
    }

    if (k != 0)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (int i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
