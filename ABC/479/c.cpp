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
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll ans = 0;
    rep(bit, 1 << n)
    {
        ll sum_a = 0, sum_b = 0;
        rep(i, n)
        {
            if ((bit >> i) % 2)
            {
                sum_a += a[i];
                sum_b += b[i];
            }
        }
        if (sum_b <= w)
        {
            ans = max(ans, sum_a);
        }
    }

    cout << ans << endl;

    return 0;
}
