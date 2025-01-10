#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> ch(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        --a[i];
        ch[a[i]].push_back(i);
    }
    vector<bool> in_cycle(n);
    vector<vector<int>> cycles;
    dsu uf(n);
    for (int i = 0; i < n; i++)
    {
        if (uf.same(i, a[i]))
        {
            cycles.emplace_back();
            int now = a[i];
            do
            {
                in_cycle[now] = true;
                cycles.back().push_back(now);
                now = a[now];
            } while (now != a[i]);
        }
        else
        {
            uf.merge(i, a[i]);
        }
    }
    vector dp(n, vector<mint>(m, 1));
    auto dfs = [&](auto &dfs, int i) -> void
    {
        for (int j : ch[i])
        {
            if (in_cycle[j])
                continue;
            dfs(dfs, j);
            mint sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum += dp[j][k];
                dp[i][k] *= sum;
            }
        }
    };
    mint ans = 1;
    for (auto cycle : cycles)
    {
        vector<mint> prod(m, 1);
        for (int i : cycle)
        {
            dfs(dfs, i);
            for (int j = 0; j < m; j++)
                prod[j] *= dp[i][j];
        }
        mint sum = 0;
        for (int j = 0; j < m; j++)
            sum += prod[j];
        ans *= sum;
    }
    cout << ans.val() << endl;
}
