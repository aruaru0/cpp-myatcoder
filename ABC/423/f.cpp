#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ull = unsigned long long;

int main()
{
    int n, m;
    ull y;
    cin >> n >> m >> y;
    vector<ull> a(n);
    rep(i, n) cin >> a[i];

    int n2 = 1 << n;
    vector<ull> d(n2);

    const ull INF = 1ull << 60;

    rep(s, n2)
    {
        ull x = 1;
        rep(i, n) if (s >> i & 1)
        {
            ull t = a[i] / gcd(x, a[i]);
            if (INF / x < t)
                x = INF;
            else
                x *= t;
        }
        d[s] = y / x;
    }

    rep(i, n) rep(s, n2) if (s >> i & 1) d[s ^ 1 << i] -= d[s];

    ull ans = 0;
    rep(s, n2) if (__builtin_popcountll(s) == m) ans += d[s];
    cout << ans << endl;
    return 0;
}