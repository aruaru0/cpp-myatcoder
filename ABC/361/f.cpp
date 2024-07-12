#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calc(int b, ll n)
{
    ll ac = 0, wa = n + 1;
    // ac^b <= n
    while (ac + 1 < wa)
    {
        ll wj = (ac + wa) / 2;
        auto judge = [&]
        {
            ll x = 1;
            rep(i, b)
            {
                if (n / x < wj)
                    return false;
                x *= wj;
            }
            return x <= n;
        };
        if (judge())
            ac = wj;
        else
            wa = wj;
    }
    return ac - 1;
}

int main()
{
    ll n;
    cin >> n;

    const int M = 60;
    vector<ll> f(M);
    ll ans = 1;
    for (int b = M - 1; b >= 2; b--)
    {
        f[b] = calc(b, n);
        for (int i = b * 2; i < M; i += b)
            f[b] -= f[i];
        ans += f[b];
    }

    cout << ans << endl;
    return 0;
}