#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll f(ll y, ll x)
{
    ll a[][5] = {{0, 0, 0, 0, 0}, {0, 2, 3, 3, 4}, {0, 3, 6, 7, 8}};

    ll sub1 = (y / 2) * (x / 4) * a[2][4];
    ll sub2 = (y / 2) * a[2][x % 4];
    ll sub3 = (x / 4) * a[y % 2][4];
    ll sub4 = a[y % 2][x % 4];
    return sub1 + sub2 + sub3 + sub4;
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    const ll m = 1000000000;
    a += m;
    b += m;
    c += m;
    d += m;
    cout << f(d, c) - f(d, a) - f(b, c) + f(b, a) << endl;
}