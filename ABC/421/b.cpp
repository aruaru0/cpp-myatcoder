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
    ll x, y;
    cin >> x >> y;

    auto f = [](ll x, ll y)
    {
        ll z = x + y;
        ll ret = 0;
        while (z > 0)
        {
            ret = ret * 10 + z % 10;
            z /= 10;
        }
        return ret;
    };

    for (int i = 2; i < 10; i++)
    {
        ll z = f(x, y);
        x = y;
        y = z;
        // cout << x << " " << y << endl;
    }

    cout << y << endl;

    return 0;
}
