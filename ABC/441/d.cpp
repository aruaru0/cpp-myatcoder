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
    ll n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<P>> node(n);
    rep(i, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        node[u].push_back(P(v, c));
    }

    set<int> st;

    auto dfs = [&](auto dfs, int cur, int cnt = 0, int cost = 0)
    {
        if (cnt == l)
        {
            if (s <= cost && cost <= t)
            {
                st.insert(cur);
            }
            return;
        }
        for (auto [to, c] : node[cur])
        {
            dfs(dfs, to, cnt + 1, cost + c);
        }
    };

    dfs(dfs, 0);

    for (auto x : st)
    {
        cout << x + 1 << " ";
    }
    cout << endl;

    return 0;
}
