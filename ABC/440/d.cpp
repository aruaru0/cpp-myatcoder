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
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    const ll inf = 1e10;
    a.push_back(inf);

    rep(qi, q)
    {
        ll x, y;
        cin >> x >> y;
        ll l = x, r = inf;

        while (l + 1 != r)
        {
            ll m = (l + r) / 2;
            ll cnt = lower_bound(a.begin(), a.end(), m) - lower_bound(a.begin(), a.end(), x);
            ll sum = m - x - cnt;
            if (y > sum)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        cout << l << endl;
    }

    return 0;
}
