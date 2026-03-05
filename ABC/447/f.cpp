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

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    int ans = 1;

    auto f = [&](auto f, int v, int p = -1) -> int
    {
        int deg = to[v].size();
        int mx = 0;
        for (int u : to[v])
        {
            if (u != p)
            {
                int r = f(f, u, v);
                if (deg >= 4)
                    ans = max(ans, mx + r + 1);
                if (deg >= 3)
                    ans = max(ans, r + 1);
                mx = max(mx, r);
            }
        }
        if (deg >= 4)
            return mx + 1;
        if (deg == 3)
            return 1;
        return 0;
    };

    f(f, 0);
    cout << ans << endl;
}

int main()
{
    int Q;
    cin >> Q;
    rep(qi, Q)
    {
        solve();
    }

    return 0;
}
