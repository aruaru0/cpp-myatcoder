#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> vid(1);
    vector<map<int, int>> to(1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        int v = vid[x], u;
        if (!to[v].count(y))
        {
            u = to.size();
            to.push_back({});
            to[v][y] = u;
        }
        else
            u = to[v][y];
        vid.push_back(u);
    }

    vector<vector<int>> is(to.size());
    for (int i = 1; i <= n; i++)
        is[vid[i]].push_back(i);

    vector<int> ans;
    auto f = [&](auto f, int v) -> void
    {
        for (int i : is[v])
            ans.push_back(i);
        for (auto p : to[v])
        {
            f(f, p.second);
        }
    };
    f(f, 0);

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}