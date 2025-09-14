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

    vector<int> l(n);
    rep(i, n) cin >> l[i];

    int lp = 0;
    int rp = 0;

    rep(i, n)
    {
        if (l[i] == 1)
        {
            lp = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (l[i] == 1)
        {
            rp = i;
            break;
        }
    }

    // cout << lp << " " << rp << endl;
    cout << rp - lp << endl;

    return 0;
}
