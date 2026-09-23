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

const int inf = 1e9;

struct S
{
    int val, idx;
};

S op_max(S a, S b)
{
    if (a.val > b.val)
    {
        return a;
    }
    return b;
}

S e_max()
{
    return {0, -1};
}

S op_min(S a, S b)
{
    if (a.val < b.val)
    {
        return a;
    }
    return b;
}

S e_min()
{
    return {inf, -1};
}

int main()
{
    int n, m;
    cin >> n >> m;

    segtree<S, op_max, e_max> seg_max(n);
    segtree<S, op_min, e_min> seg_min(n);
    rep(i, n)
    {
        int p;
        cin >> p;
        seg_max.set(i, {p, i});
        seg_min.set(i, {p, i});
    }

    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        l--;

        auto max_val = seg_max.prod(l, r);
        auto min_val = seg_min.prod(l, r);

        // cout << "----" << l << " " << r << endl;
        // cout << min_val.idx << " " << max_val.idx << endl;
        // cout << min_val.val << " " << max_val.val << endl;

        swap(min_val.idx, max_val.idx);
        seg_max.set(max_val.idx, max_val);
        seg_max.set(min_val.idx, min_val);

        seg_min.set(max_val.idx, max_val);
        seg_min.set(min_val.idx, min_val);
    }

    rep(i, n)
    {
        auto e = seg_max.get(i);
        cout << e.val << " ";
    }
    cout << endl;

    return 0;
}
