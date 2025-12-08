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
    int n, m;
    cin >> n >> m;

    // vector node(n, vector<int>());
    vector<vector<int>> node(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        node[v].push_back(u);
    }

    vector<bool> ok(n);

    auto dfs = [&](auto dfs, int cur) -> void
    {
        if (ok[cur])
            return;
        ok[cur] = true;
        for (auto e : node[cur])
        {
            dfs(dfs, e);
        }
    };

    int q;
    cin >> q;
    rep(qi, q)
    {
        int t, v;
        cin >> t >> v;
        v--;
        if (t == 1)
        {
            dfs(dfs, v);
        }
        else
        {
            if (ok[v])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
