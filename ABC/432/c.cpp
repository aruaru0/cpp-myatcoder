#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

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
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    // cout << a << endl;

    ll w = a[0] * y;
    ll ans = 0;
    rep(i, n)
    {
        ll sw = a[i] * y;
        ll dif = sw - w;
        if (dif % (y - x) != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        ll num = dif / (y - x);
        if (num > a[i])
        {
            cout << -1 << endl;
            return 0;
        }
        ans += a[i] - num;
    }
    cout << ans << endl;
    return 0;
}
