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
    int h, w, q;
    cin >> h >> w >> q;

    rep(qi, q)
    {
        int t, n;
        cin >> t >> n;
        if (t == 1)
        {
            cout << w * n << endl;
            h -= n;
        }
        else
        {
            cout << h * n << endl;
            w -= n;
        }
    }

    return 0;
}
