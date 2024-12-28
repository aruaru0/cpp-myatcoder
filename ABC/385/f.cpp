#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V
{
    ll x, y;
    V(ll x = 0, ll y = 0) : x(x), y(y) {}
    V &operator+=(const V &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    V operator+(const V &v) const { return V(*this) += v; }
    V &operator-=(const V &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    V operator-(const V &v) const { return V(*this) -= v; }
    V &operator*=(ll s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    V operator*(ll s) const { return V(*this) *= s; }
    ll cross(const V &v) const { return x * v.y - v.x * y; }
};
istream &operator>>(istream &is, V &v)
{
    is >> v.x >> v.y;
    return is;
}
ostream &operator<<(ostream &os, const V &v)
{
    os << "(" << v.x << "," << v.y << ")";
    return os;
}

int main()
{
    int n;
    cin >> n;

    double ans = -100;
    bool all = true;

    vector<V> conv;
    rep(i, n)
    {
        ll x, h;
        cin >> x >> h;
        V p(x, h);
        while (conv.size() >= 2)
        {
            V a = conv.back(), b = conv.end()[-2];
            if ((p.y - a.y) * (p.x - b.x) < (p.y - b.y) * (p.x - a.x))
                break;
            conv.pop_back();
        }
        if (conv.size() >= 1)
        {
            V a = conv.back();
            ll dy = a.y - p.y, dx = p.x - a.x;
            double y = double(dy * p.x + p.y * dx) / dx;
            if ((a.y - p.y) * p.x >= -p.y * (p.x - a.x))
                all = false;
            ans = max(y, ans);
        }
        conv.push_back(p);
    }

    if (all)
        cout << -1 << endl;
    else
        printf("%.10f\n", ans);
    return 0;
}