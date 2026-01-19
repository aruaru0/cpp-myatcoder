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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = n - k; // 水は全部飲む
    int cur = k - 1; // お酒で一番大きい方から飲む

    while (x > 0 && cur >= 0)
    {
        x -= a[cur];
        cnt++;
        cur--;
    }

    if (x > 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << cnt << endl;
    }

    return 0;
}
