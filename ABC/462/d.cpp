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
    int n, d;
    cin >> n >> d;
    const int size = 1e6 + 100;

    vector<int> a(size);
    rep(i, n)
    {
        int s, t;
        cin >> s >> t;
        if (t - d >= s)
        {
            a[s]++;
            a[t - d + 1]--;
        }
    }

    rep(i, size)
    {
        a[i + 1] += a[i];
    }

    ll ans = 0;
    rep(i, size)
    {
        ll d = a[i];
        ans += d * (d - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
