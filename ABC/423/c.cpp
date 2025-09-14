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
    int n, r;
    cin >> n >> r;

    vector<int> l(n);
    rep(i, n) cin >> l[i];

    vector<int> idx;
    rep(i, n) if (l[i] == 0) idx.push_back(i);

    if (idx.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int lc = max(0, r - idx[0]);
    int rc = max(0, idx[idx.size() - 1] - r + 1);

    // cout << lc << " " << rc << endl;

    for (int i = idx[0]; i < r; i++)
    {
        if (l[i] == 1)
        {
            lc++;
        }
    }

    for (int i = r; i <= idx[idx.size() - 1]; i++)
    {
        if (l[i] == 1)
        {
            rc++;
        }
    }

    // cout << lc << " " << rc << endl;
    cout << lc + rc << endl;
    return 0;
}
