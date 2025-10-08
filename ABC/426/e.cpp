#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

// Geometry
const double eps = 1e-9;
bool equal(double a, double b) { return abs(a - b) < eps; }

// Vector
// https://youtu.be/UWbGRhF3Ozw?t=9564
struct V
{
    double x, y;
    V(double x = 0, double y = 0) : x(x), y(y) {}
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
    V &operator*=(double s)
    {
        x *= s;
        y *= s;
        return *this;
    }
    V operator*(double s) const { return V(*this) *= s; }
    V &operator/=(double s)
    {
        x /= s;
        y /= s;
        return *this;
    }
    V operator/(double s) const { return V(*this) /= s; }
    double dot(const V &v) const { return x * v.x + y * v.y; }
    double cross(const V &v) const { return x * v.y - v.x * y; }
    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    V normalize() const { return *this / norm(); }
    V rotate90() const { return V(y, -x); }
    int ort() const
    { // orthant
        if (abs(x) < eps && abs(y) < eps)
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
    double norm() const { return dir().norm(); }
    /* +1: s-t,s-p : ccw
     * -1: s-t,s-p : cw
     * +2: t-s-p
     * -2: s-t-p
     *  0: s-p-t */
    int ccw(const V &p) const
    {
        if (dir().cross(p - s) > eps)
            return +1;
        if (dir().cross(p - s) < -eps)
            return -1;
        if (dir().dot(p - s) < -eps)
            return +2;
        if (dir().dot(t - p) < -eps)
            return -2;
        return 0;
    }
    bool touch(const Line &l) const
    {
        int a = ccw(l.s) * ccw(l.t), b = l.ccw(s) * l.ccw(t);
        return !a || !b || (a == -1 && b == -1);
    }

    V divpoint(double p) const
    {
        return s * (1 - p) + t * p;
    }
    double distSP(V p) const
    {
        if ((p - s).dot(t - s) < eps)
            return (s - p).norm();
        if ((p - t).dot(s - t) < eps)
            return (t - p).norm();
        return abs((s - p).cross(t - p)) / (t - s).norm();
    }
};

void solve()
{
    Line t, a;
    cin >> t.s >> t.t >> a.s >> a.t;
    if (t.norm() < a.norm())
        swap(t, a);

    double tlen = t.norm();
    double alen = a.norm();
    double ans = 1e18;
    {
        Line l;
        l.s = t.s - a.s;
        l.t = t.divpoint(alen / tlen) - a.t;
        ans = min(ans, l.distSP(V(0, 0)));
    }
    {
        Line l;
        l.s = t.divpoint(alen / tlen) - a.t;
        l.t = t.t - a.t;
        ans = min(ans, l.distSP(V(0, 0)));
    }
    printf("%.10f\n", ans);
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}