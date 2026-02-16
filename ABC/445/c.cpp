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
    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<int> dist(n, -1);

    auto dfs = [&](auto dfs, int cur) -> int
    {
        if (dist[cur] != -1)
            return dist[cur];
        if (a[cur] == cur)
        {
            dist[cur] = cur;
        }
        else
        {
            dist[cur] = dfs(dfs, a[cur]);
        }
        return dist[cur];
    };

    rep(i, n)
    {
        if (dist[i] == -1)
            dfs(dfs, i);
    }

    rep(i, n) cout << dist[i] + 1 << " ";
    cout << endl;

    return 0;
}
