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

int e()
{
    return 0;
}

int op(int a, int b)
{
    return min(a, b);
}

int main()
{
    int Q;
    cin >> Q;

    segtree<int, op, e> seg(Q + 1);
    vector<char> s;
    int tot = 0;
    rep(qi, Q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            string x;
            cin >> x;
            s.push_back(x[0]);
            if (x[0] == '(')
            {
                tot++;
            }
            else
            {
                tot--;
            }
            seg.set(s.size(), tot);
        }
        else
        {
            if (s[s.size() - 1] == '(')
            {
                tot--;
            }
            else
            {
                tot++;
            }
            s.pop_back();
        }
        // cout << tot << endl;
        int min_val = seg.prod(0, s.size());
        if (min_val >= 0 && tot == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
