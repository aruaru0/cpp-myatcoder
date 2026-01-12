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
    int n, w;
    cin >> n >> w;

    int m = w * 2;
    vector<ll> c(m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c[i % m] += x;
    }

    ll cur = 0;
    rep(i, w)
    {
        cur += c[i];
    }
    ll ans = cur;
    rep(i, m)
    {
        cur -= c[i];
        cur += c[(i + w) % m];
        ans = min(ans, cur);
    }

    cout << ans << endl;
}

int main()
{
    int t;

    cin >> t;
    rep(i, t) solve();

    return 0;
}
