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
    vector<int> h(n), l(n);
    rep(i, n)
    {
        cin >> h[i] >> l[i];
    }

    vector<int> p(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        p[i] = max(p[i + 1], h[i]);
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int t;
        cin >> t;
        int pos = upper_bound(l.begin(), l.end(), t) - l.begin();
        cout << p[pos] << endl;
    }

    return 0;
}
