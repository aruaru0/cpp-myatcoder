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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int N = 500010;
    fenwick_tree<ll> sum(N + 1);
    fenwick_tree<int> cnt(N + 1);

    rep(i, n)
    {
        sum.add(a[i], a[i]);
        cnt.add(a[i], 1);
    }

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            sum.add(a[x], -a[x]);
            sum.add(y, y);
            cnt.add(a[x], -1);
            cnt.add(y, 1);
            a[x] = y;
        }
        else
        {
            int l, r;
            cin >> l >> r;

            if (l > r)
            {
                cout << (ll)l * n << endl;
            }
            else
            {
                ll a, b, c;
                a = cnt.sum(0, l);
                b = sum.sum(l, r);
                c = cnt.sum(r, N);
                cout << a * l + b + c * r << endl;
            }
        }
    }

    return 0;
}
