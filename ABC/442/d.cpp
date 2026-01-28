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

int op(int a, int b)
{
    return a + b;
}

int e()
{
    return (int)0;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    segtree<int, op, e> seg(a);

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x--;
            swap(a[x], a[x + 1]);
            seg.set(x, a[x]);
            seg.set(x + 1, a[x + 1]);

            // rep(i, n)
            // {
            //     cout << seg.get(i) << endl;
            // }
            // cout << "-----" << endl;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        }
    }

    return 0;
}
