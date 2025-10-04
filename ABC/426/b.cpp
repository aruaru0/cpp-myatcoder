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
    string s;
    cin >> s;

    map<char, int> m;

    rep(i, s.size())
    {
        m[s[i]]++;
    }

    for (auto [e, n] : m)
    {
        if (n == 1)
            cout << e << endl;
    }

    return 0;
}
