#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
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

void solve()
{
    int n, h;
    cin >> n >> h;

    bool ok = true;
    int cl = h, cu = h;
    int pre = 0;
    rep(i, n)
    {
        int t, l, u;
        cin >> t >> l >> u;
        int dt = t - pre;
        pre = t;
        int nl = max(0, cl - dt);
        int nu = cu + dt;
        if (l > nu || u < nl)
        {
            ok = false;
        }
        cl = max(nl, l);
        cu = min(nu, u);
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(ti, t) solve();

    return 0;
}
