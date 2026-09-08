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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> a(q);
    rep(i, q) cin >> a[i];

    set<int> s;
    vector<int> b;
    for (int qi = q - 1; qi >= 0; qi--)
    {
        if (s.find(a[qi]) == s.end())
        {
            s.insert(a[qi]);
            b.push_back(a[qi]);
        }
    }

    rep(i, n)
    {
        if (s.find(p[i]) == s.end())
        {
            cout << p[i] << " ";
        }
    }
    reverse(b.begin(), b.end());
    for (auto e : b)
        cout << e << " ";
    cout << endl;

    return 0;
}
