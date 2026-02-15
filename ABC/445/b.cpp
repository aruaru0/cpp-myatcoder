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
    int n;
    cin >> n;
    vector<string> s(n);
    int m;
    rep(i, n)
    {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }

    rep(i, n)
    {
        int d = (m - s[i].size()) / 2;
        rep(j, d)
        {
            cout << ".";
        }
        cout << s[i];
        rep(j, d)
        {
            cout << ".";
        }
        cout << endl;
    }

    return 0;
}
