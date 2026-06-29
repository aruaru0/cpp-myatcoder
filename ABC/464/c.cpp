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

struct col
{
    int a, d, b;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<col> c(n);
    rep(i, n)
    {
        cin >> c[i].a >> c[i].d >> c[i].b;
    }

    sort(c.begin(), c.end(), [](col a, col b) -> bool
         { return a.d < b.d; });

    map<int, int> mp;
    rep(i, n)
    {
        mp[c[i].a]++;
    }

    int cur = 0;
    for (int i = 1; i <= m; i++)
    {
        while (cur != n && c[cur].d == i)
        {
            mp[c[cur].a]--;
            if (mp[c[cur].a] == 0)
                mp.erase(c[cur].a);
            mp[c[cur].b]++;
            cur++;
        }
        cout << mp.size() << endl;
    }

    return 0;
}
