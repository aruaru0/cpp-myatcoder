#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> node(n);

    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    vector<bool> ok(n, false);
    map<int, int> cnt;

    auto dfs = [&](auto dfs, int cur, int prev = -1) -> void
    {
        int idx = a[cur];
        cnt[idx]++;
        if ((prev != -1 && ok[prev]) || cnt[idx] >= 2)
        {
            ok[cur] = true;
        }
        for (auto e : node[cur])
        {
            if (e == prev)
                continue;
            dfs(dfs, e, cur);
        }
    };

    dfs(dfs, 0);

    rep(i, n)
    {
        if (ok[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
