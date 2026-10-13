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

const int inf = 2e9 + 100;

int e()
{
    return inf;
}

int op(int a, int b)
{
    return min(a, b);
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> l(n), r(n);
    l[0] = inf;
    rep(i, n - 1) cin >> l[i + 1];
    r[n - 1] = inf;
    rep(i, n - 1) cin >> r[i];

    segtree<int, op, e> seg_l(l), seg_r(r);

    rep(qi, q)
    {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        int ans = 0;
        if (s == 0)
        {
            ans = r[0];
        }
        else if (s == n - 1)
        {
            ans = l[n - 1];
        }
        else if (s < t)
        {
            ans = min(r[s], l[s] + seg_r.prod(0, s));
        }
        else
        {
            ans = min(l[s], r[s] + seg_l.prod(s, n));
        }
        cout << ans << endl;
    }

    return 0;
}
