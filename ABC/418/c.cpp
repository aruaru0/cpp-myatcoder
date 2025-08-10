#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
    const ll maxn = 1e6 + 1;
    fenwick_tree<ll> bit(maxn);

    ll max_a = 0;
    rep(i, n)
    {
        cin >> a[i];
        max_a = max(max_a, a[i]);
        bit.add(a[i], 1);
    }

    sort(a.begin(), a.end());
    vector<ll> p(n + 1);
    rep(i, n)
    {
        p[i + 1] = p[i] + a[i];
    }

    rep(qi, q)
    {
        ll b;
        cin >> b;

        if (max_a < b)
        {
            cout << -1 << endl;
            continue;
        }

        ll low = bit.sum(0, b);
        ll high = bit.sum(b, maxn);

        ll ans = p[low] + high * (b - 1) + 1;

        cout << ans << endl;
    }
}
