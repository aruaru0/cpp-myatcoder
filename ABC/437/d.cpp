#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
using mint = modint998244353;

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(m);
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<mint> bsum(m + 1);
    rep(i, m) bsum[i + 1] = bsum[i] + b[i];

    mint ans = 0;
    rep(i, n)
    {
        int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        mint l = bsum[idx], r = bsum[m] - bsum[idx];
        mint ln = idx, rn = m - idx;
        mint tot = ln * a[i] - l + r - rn * a[i];
        ans += tot;
    }

    cout << ans.val() << endl;

    return 0;
}
