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

struct pos
{
    int l, r;
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pos> p(n);
    rep(i, n)
    {
        cin >> p[i].l >> p[i].r;
    }
    sort(p.begin(), p.end(), [](const pos &a, const pos &b)
         {
        if (a.r == b.r) {
            return a.l < b.l;
        }
        return a.r < b.r; });

    auto ok = [&](int x) -> bool
    {
        int cnt = 1;
        int last = p[0].r;
        int r = 0;
        rep(l, n)
        {
            while (r < n && p[r].l < last + x)
            {
                r++;
            }
            if (r == n)
            {
                break;
            }
            cnt++;
            last = p[r].r;
        }
        return cnt >= k;
    };

    const int inf = 1e9 + 100;
    int l = 0, r = inf;
    while (l + 1 != r)
    {
        int m = (l + r) / 2;
        if (!ok(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    if (l == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << l << endl;

    return 0;
}
