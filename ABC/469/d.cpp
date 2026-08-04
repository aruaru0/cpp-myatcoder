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

    vector<int> deg(n);
    map<P, int> edge;

    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        if (u > v)
            swap(u, v);
        edge[{u, v}]++;
    }

    vector<int> sorted = deg;
    sort(sorted.begin(), sorted.end());

    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (sorted[l] + sorted[r] >= m)
        {
            ans += r - l;
            r--;
        }
        else
        {
            l++;
        }
    }

    for (auto [e, c] : edge)
    {
        auto [u, v] = e;
        if (deg[u] + deg[v] >= m && deg[u] + deg[v] - c < m)
        {
            ans--;
        }
    }

    cout << ans << endl;

    return 0;
}
