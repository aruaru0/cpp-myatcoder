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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int x1 = 0, x10 = 0, x100 = 0;
    rep(i, n)
    {
        int diff = (a[i] + 999) / 1000 * 1000 - a[i];
        x1 += diff % 10;
        x10 += diff / 10 % 10;
        x100 += diff / 100 % 10;
    }

    cout << x1 << " " << x10 << " " << x100 << endl;

    return 0;
}
