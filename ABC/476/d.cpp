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
    int n, m, k;
    cin >> n >> m >> k;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> c(n + 1);
    rep(i, n) c[i + 1] = c[i] + a[i];

    int ans = upper_bound(c.begin(), c.end(), x + y * k) - c.begin() - 1;

    int cnt = 0;
    ll sum = 0;
    rep(i, m)
    {
        int d = (b[i] + k - 1) / k;
        cnt += d;
        if (cnt > y)
        {
            break;
        }
        sum += b[i];
        ll rest = x + y * k - sum;
        int pos = upper_bound(c.begin(), c.end(), rest) - c.begin();
        ans = max(ans, pos + i);
    }

    cout << ans << endl;

    return 0;
}
