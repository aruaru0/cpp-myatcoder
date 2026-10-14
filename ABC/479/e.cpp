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

    vector<int> a(n - 1), b(n - 1);
    vector<vector<P>> edge(n);
    rep(i, n - 1)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        edge[a[i]].push_back(P(b[i], i));
        edge[b[i]].push_back(P(a[i], i));
    }

    vector<int> path;
    vector<vector<int>> edges(n - 1);

    auto dfs = [&](auto &dfs, int cur, int prev = -1) -> void
    {
        path.push_back(cur);

        for (auto &e : edge[cur])
        {
            if (e.first == prev)
                continue;
            edges[e.second].push_back(size(path));
            dfs(dfs, e.first, cur);
            edges[e.second].push_back(size(path));
        }

        path.push_back(cur);
    };

    dfs(dfs, 0);

    vector<ll> cnt(size(path) + 1);
    rep(i, n - 1)
    {
        int l = edges[i][0], r = edges[i][1];
        int x = r - l, y = size(path) - (r - l);
        int d = i + 1;
        if (x > y)
        {
            cnt[l] += d;
            cnt[r] -= d;
        }
        else
        {
            cnt[0] += d;
            cnt[size(path)] -= d;
            cnt[l] -= d;
            cnt[r] += d;
        }
    }

    rep(i, size(path))
    {
        cnt[i + 1] += cnt[i];
    }

    vector<ll> ans(n);
    rep(i, size(path))
    {
        ans[path[i]] = cnt[i];
    }

    rep(i, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
