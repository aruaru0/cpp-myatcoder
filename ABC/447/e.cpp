#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;
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

    vector<P> edge(m);
    rep(i, m)
    {
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--;
        edge[i].second--;
    }

    vector<mint> cost(m);
    cost[0] = 2;
    for (int i = 1; i < m; i++)
    {
        cost[i] = cost[i - 1] * 2;
    }

    dsu uf(n);
    int g = n;
    mint ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        int u = edge[i].first, v = edge[i].second;
        if (uf.same(u, v))
        {
            continue;
        }
        if (g > 2)
        {
            g--;
            uf.merge(u, v);
        }
        else
        {
            ans += cost[i];
        }
    }

    cout << ans.val() << endl;

    return 0;
}
