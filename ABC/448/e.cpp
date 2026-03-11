#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
const int p = 10007;

int main()
{
    int k, m;
    cin >> k >> m;
    vector<pair<int, int>> cl;
    rep(i, k)
    {
        int c, l;
        cin >> c >> l;
        cl.emplace_back(c, l);
    }

    auto pow = [&](ll x, int l, int mod)
    {
        ll res = 1;
        while (l)
        {
            if (l % 2)
                res = res * x % mod;
            x = x * x % mod;
            l /= 2;
        }
        return res;
    };
    auto repunit = [&](int l, int mod)
    {
        ll res = 0, x = 1, ten = 10;
        while (l)
        {
            if (l % 2)
                res = (res * ten + x) % mod;
            x = (x * ten + x) % mod;
            ten = ten * ten % mod;
            l /= 2;
        }
        return res;
    };
    auto f = [&](int mod)
    {
        ll res = 0;
        for (auto [c, l] : cl)
        {
            res = res * pow(10, l, mod) + repunit(l, mod) * c;
            res %= mod;
        }
        return res;
    };

    ll ans = (f(p) - f(m) + p) * pow(m, p - 2, p) % p;
    cout << ans << endl;
    return 0;
}