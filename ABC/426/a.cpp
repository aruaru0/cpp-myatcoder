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
    string x, y;
    cin >> x >> y;

    map<string, int> m = {{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};

    if (m[x] >= m[y])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
