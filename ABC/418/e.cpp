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

int gcd(int a, int b)
{

    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    map<P, int> p, q;
    rep(i, n) for (int j = i + 1; j < n; j++)
    {
        int dx, dy;
        dx = x[i] - x[j];
        dy = y[i] - y[j];
        if (dx < 0)
        {
            dx = -dx;
            dy = -dy;
        }
        if (dx == 0 || dy == 0)
        {
            dx = abs(dx);
            dy = abs(dy);
        }

        q[{dx, dy}]++;
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        p[{dx, dy}]++;
    }

    ll ans = 0;
    for (auto [v, e] : p)
    {
        ans += (ll)e * (e - 1) / 2;
    }
    ll tot = 0;
    for (auto [v, e] : q)
    {
        tot += (ll)e * (e - 1) / 2;
    }

    cout << ans - tot / 2 << endl;

    return 0;
}
