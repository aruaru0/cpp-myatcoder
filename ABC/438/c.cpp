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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> b(0);
    rep(i, n)
    {
        b.push_back(a[i]);
        // cout << b << endl;
        if (b.size() < 4)
            continue;
        if (b[b.size() - 4] == b[b.size() - 3] && b[b.size() - 3] == b[b.size() - 2] && b[b.size() - 2] == b[b.size() - 1])
        {
            b.pop_back();
            b.pop_back();
            b.pop_back();
            b.pop_back();
        }
    }

    cout << b.size() << endl;

    return 0;
}
