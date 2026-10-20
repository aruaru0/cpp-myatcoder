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
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> q(n + 1);
    ll p = 0;
    rep(i, n)
    {
        p += (i + 1);
        q[i + 1] = q[0] + p;
    }

    vector<ll> pa(n + 1), acc(n + 1);
    rep(i, n) pa[i + 1] = pa[i] + a[i];
    rep(i, n) acc[i + 1] = acc[i] + pa[i + 1];

    auto f = [&](ll t) -> ll
    {
        if (t <= 0)
            return 0;
        int i = lower_bound(q.begin(), q.end(), t) - q.begin();
        ll k = t - q[i - 1];
        return acc[i - 1] + pa[k];
    };

    rep(qi, Q)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = f(r) - f(l - 1);
        cout << ans << endl;
    }

    return 0;
}
