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

const int INF = 1e7;

int e_max()
{
    return -INF;
}

int e_min()
{
    return INF;
}

int op_max(int a, int b)
{
    return max(a, b);
}

int op_min(int a, int b)
{
    return min(a, b);
}

int main()
{
    int n, q;
    cin >> n >> q;

    segtree<int, op_max, e_max> seg_max(n); // 始点のセグ木
    segtree<int, op_min, e_min> seg_min(n); // 終点のセグ木

    rep(qi, q)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int mi = seg_min.prod(a, b);
        int mx = seg_max.prod(a, b);

        if (mx > b || mi < a)
        {
            cout << "No" << endl;
        }
        else
        {
            seg_min.set(b, a);
            seg_max.set(a, b);
            cout << "Yes" << endl;
        }

        // rep(i, n)
        // {
        //     cout << seg_max.prod(i, i + 1) << " " << seg_min.prod(i, i + 1) << endl;
        // }
    }

    return 0;
}
