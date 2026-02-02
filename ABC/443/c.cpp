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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;
    int cur = 0;

    rep(i, n)
    {
        if (cur > a[i])
        {
            continue;
        }
        ans += a[i] - cur;
        cur = a[i] + 100;
    }

    if (cur < t)
    {
        ans += t - cur;
    }

    cout << ans << endl;

    return 0;
}
