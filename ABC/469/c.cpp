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
    string s;
    cin >> s;

    vector<int> p;
    rep(i, n)
    {
        if (s[i] == 'x')
            p.push_back(i + 1);
    }

    int idx = 0;
    rep(i, n)
    {
        if (p.size() == idx)
            cout << n << endl;
        else
        {
            cout << p[idx] << endl;
            idx++;
        }
    }

    return 0;
}
