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

struct Data
{
    int sum;
    int min;
};

Data op(Data a, Data b)
{
    return Data{a.sum + b.sum, min(a.min, a.sum + b.min)};
}

Data e()
{
    return Data{0, 0};
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<Data> v(n);
    rep(i, n)
    {
        if (s[i] == 'A')
        {
            v[i] = Data{1, 1};
        }
        else
        {
            v[i] = Data{-1, -1};
        }
    }

    segtree<Data, op, e> seg(v);

    int q;
    cin >> q;
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            char c;
            cin >> i >> c;
            i -= 1;
            if (c == 'A')
            {
                seg.set(i, Data{1, 1});
            }
            else
            {
                seg.set(i, Data{-1, -1});
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            auto [sum, mi] = seg.prod(l, r);
            if (sum >= 0 && mi >= 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
