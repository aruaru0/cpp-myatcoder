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
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll tot = 0;
    rep(i, n) tot += min(a[i], b[i]);

    rep(qi, q)
    {
        char c;
        int x, v;
        cin >> c >> x >> v;
        x--;
        tot -= min(a[x], b[x]);
        if (c == 'A')
        {
            a[x] = v;
        }
        else
        {
            b[x] = v;
        }
        tot += min(a[x], b[x]);
        cout << tot << endl;
    }

    return 0;
}
