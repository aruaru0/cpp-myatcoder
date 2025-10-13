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

    vector<P> edge(m);
    rep(i, m) cin >> edge[i].first >> edge[i].second;

    int ans = 1e9;
    rep(bit, 1 << n)
    {
        int cnt = 0;
        for (auto [u, v] : edge)
        {
            if (((bit >> u) & 1) == ((bit >> v) & 1))
            {
                cnt++;
            }
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
