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
    ll min_a = 1e9;
    vector<ll> diff(n);
    ll tot = 0;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        tot += a;
        diff[i] = b - a;
        min_a = min(min_a, a);
    }

    sort(diff.begin(), diff.end());
    ll ans = tot, cur = tot;
    for (int k = 1; k <= n; k++)
    {
        cur += diff[k - 1];
        ans = min(ans, cur + max(0, 2 * k - n) * min_a);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
