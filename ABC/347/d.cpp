#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll a, b, C;
    cin >> a >> b >> C;

    vector<int> c;
    ll cnt = 0;
    for (ll i = 0; i < 60; i++)
    {
        ll val = (C >> i) % 2;
        c.push_back(val);
        cnt += val;
    }

    ll diff = a + b - cnt;

    if (diff < 0 || diff % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    diff /= 2;
    ll am = a - diff;
    ll bm = b - diff;

    if (diff > 60 - cnt || am < 0 || bm < 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll x = 0, y = 0;

    for (ll i = 0; i < 60; i++)
    {
        if ((am != 0) && (c[i] == 1))
        {
            x |= (1LL << i);
            am--;
        }
        else if ((bm != 0) && c[i] == 1)
        {
            y |= (1LL << i);
            bm--;
        }
    }

    for (ll i = 0; i < 60; i++)
    {
        if ((diff != 0) && c[i] == 0)
        {
            x |= (1LL << i);
            y |= (1LL << i);
            diff--;
        }
    }

    if ((x ^ y) != C)
    {
        cout << "Error" << endl;
    }
    cout << x << " " << y << endl;

    return 0;
}