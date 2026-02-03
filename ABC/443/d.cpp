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

    int t;

    cin >> t;

    rep(qi, t)
    {

        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];

        vector<int> l(n);
        l[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            l[i] = min(a[i], l[i - 1] + 1);
        }
        vector<int> r(n);
        r[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            r[i] = min(a[i], r[i + 1] + 1);
        }

        ll ans = 0;
        rep(i, n) ans += a[i] - min(l[i], r[i]);

        cout << ans << endl;
    }
    return 0;
}
