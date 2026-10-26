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
    int q;
    cin >> q;

    map<string, int> m;
    rep(i, q)
    {
        string s;
        cin >> s;
        if (m.find(s) == m.end())
        {
            m[s] = m.size() + 1;
        }
        cout << m[s] << endl;
    }

    return 0;
}
