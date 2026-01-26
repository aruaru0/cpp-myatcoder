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

int main()
{
    int n, m;

    cin >> n >> m;

    vector<set<int>> g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a - 1].insert(b - 1);
        g[b - 1].insert(a - 1);
    }

    rep(i, n)
    {
        ll d = g[i].size();
        ll r = n - 1 - d;
        cout << r * (r - 1) * (r - 2) / 6 << " ";
    }
    cout << endl;

    return 0;
}
