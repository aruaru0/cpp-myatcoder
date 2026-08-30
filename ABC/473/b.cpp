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
    map<int, int> a;
    rep(i, n)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    int tot = 0;
    for (auto [key, val] : a)
    {
        if (val % 2 == 1)
        {
            tot += key;
        }
    }

    cout << tot << endl;

    return 0;
}
