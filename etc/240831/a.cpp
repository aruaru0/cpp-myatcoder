#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k;
    cin >> k;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll p = std::abs(x1 - x2), q = std::abs(y1 - y2);
    ll t = std::abs(p + q), u = std::abs(p - q);
    cout << (t + 2 * k - 1) / (2 * k) + (u + 2 * k - 1) / (2 * k) << endl;
}
