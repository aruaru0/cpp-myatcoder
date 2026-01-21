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
    string s;
    cin >> s;

    vector<int> p(n + 1, 0);
    rep(i, n)
    {
        if (s[i] == 'A')
        {
            p[i + 1] = p[i] + 1;
        }
        else if (s[i] == 'B')
        {
            p[i + 1] = p[i] - 1;
        }
        else
        {
            p[i + 1] = p[i];
        }
    }

    int mx = 2 * n + 10;
    int off = mx / 2;
    fenwick_tree<int> bit(mx);
    ll ans = 0;
    for (auto i : p)
    {
        int idx = i + off;
        ll cnt = bit.sum(0, idx);
        ans += cnt;
        bit.add(idx, 1);
    }

    cout << ans << endl;
    return 0;
}
