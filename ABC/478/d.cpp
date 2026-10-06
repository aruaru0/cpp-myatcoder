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

struct area
{
    int l, r, x;
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<area> a(q);
    rep(i, q)
    {
        cin >> a[i].l >> a[i].r >> a[i].x;
        a[i].l--;
    }

    sort(a.begin(), a.end(), [](area a, area b)
         {
        if (a.x == b.x)
        {
            return a.l < b.l;
        }
        return a.x < b.x; });

    int cur = -1;
    int last_r = 0;
    vector<int> p(n + 1, 0);
    rep(i, q)
    {
        auto [l, r, x] = a[i];
        if (cur != x)
        {
            last_r = 0;
        }
        l = max(l, last_r);
        if (l < r)
        {
            p[l]++;
            p[r]--;
        }
        last_r = max(last_r, r);
        cur = a[i].x;
    }

    rep(i, n)
    {
        p[i + 1] += p[i];
    }

    rep(i, n)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}
