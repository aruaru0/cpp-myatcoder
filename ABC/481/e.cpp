#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Geometry
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
    V &operator/=(ll s)
    {
        x /= s;
        y /= s;
        return *this;
    }
    V operator/(ll s) const { return V(*this) /= s; }
    ll dot(const V &v) const { return x * v.x + y * v.y; }
    ll cross(const V &v) const { return x * v.y - v.x * y; }
    ll norm2() const { return x * x + y * y; }
    ll norm() const { return sqrt(norm2()); }
    V normalize() const { return *this / norm(); }
    V rotate90() const { return V(y, -x); }
    int ort() const
    { // orthant
        if (abs(x) < 0 && abs(y) < 0)
            return 0;
        if (y > 0)
            return x > 0 ? 1 : 2;
        else
            return x > 0 ? 4 : 3;
    }
    bool operator<(const V &v) const
    {
        int o = ort(), vo = v.ort();
        if (o != vo)
            return o < vo;
        return cross(v) > 0;
    }
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
struct Line
{
    V s, t;
    Line(V s = V(0, 0), V t = V(0, 0)) : s(s), t(t) {}
    V dir() const { return t - s; }
    V normalize() const { return dir().normalize(); }
    ll norm() const { return dir().norm(); }
    /* +1: s-t,s-p : ccw
     * -1: s-t,s-p : cw
     * +2: t-s-p
     * -2: s-t-p
     *  0: s-p-t */
    int ccw(const V &p) const
    {
        if (dir().cross(p - s) > 0)
            return +1;
        if (dir().cross(p - s) < 0)
            return -1;
        if (dir().dot(p - s) < 0)
            return +2;
        if (dir().dot(t - p) < 0)
            return -2;
        return 0;
    }
    bool touch(const Line &l) const
    {
        int a = ccw(l.s) * ccw(l.t), b = l.ccw(s) * l.ccw(t);
        return !a || !b || (a == -1 && b == -1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<V> ps(n);
    rep(i, n) cin >> ps[i];
    sort(ps.begin(), ps.end());
    rep(i, n) ps.push_back(ps[i]);

    int ans = 0;
    int l = 0;
    rep(r, n * 2)
    {
        while (r - l >= n || Line(V(), ps[r]).ccw(ps[l]) > 0)
            l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}