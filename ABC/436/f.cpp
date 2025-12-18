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
    int n;
    cin >> n;

    vector<int> b(n);
    rep(i, n) cin >> b[i];

    fenwick_tree<int> bit_l(n + 1), bit_r(n + 1);
    vector<int> L(n), R(n);

    rep(i, n)
    {
        int cnt = bit_l.sum(0, b[i]) + 1;
        L[i] = cnt;
        bit_l.add(b[i], 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = bit_r.sum(0, b[i]) + 1;
        R[i] = cnt;
        bit_r.add(b[i], 1);
    }

    ll ans = 0;
    rep(i, n)
    {
        ans += (ll)L[i] * R[i];
    }
    cout << ans << endl;

    return 0;
}
