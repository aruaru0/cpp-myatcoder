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

    vector<vector<int>> node(n);
    deque<int> q;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            q.push_back(i);
        }
        else
        {
            a--;
            b--;
            node[a].push_back(i);
            node[b].push_back(i);
        }
    }

    vector<bool> used(n);
    auto dfs = [&](auto dfs, int cur) -> void
    {
        used[cur] = true;
        for (auto e : node[cur])
        {
            if (used[e])
                continue;
            dfs(dfs, e);
        }
    };

    for (auto e : q)
    {
        dfs(dfs, e);
    }

    int ans = 0;
    rep(i, n)
    {
        if (used[i])
            ans++;
    }
    cout << ans << endl;

    return 0;
}
