#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int m = 6;
    vector<int> ten(m + 1, 1);
    rep(i, m) ten[i + 1] = ten[i] * 10;
    int M = ten[m];

    vector<ll> d(M);
    rep(i, n)
    {
        int s, v;
        cin >> s >> v;
        d[s] += v;
    }

    rep(k, m)
    {
        rep(i, M)
        {
            if (i / ten[k] % 10 == 9)
                continue;
            d[i + ten[k]] += d[i];
        }
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int x, y;
        cin >> x >> y;
        ll ans = 0;
        rep(s, 1 << m)
        {
            int r = 0, sign = 1;
            rep(i, m)
            {
                int c = y / ten[i] % 10;
                if (s >> i & 1)
                {
                    sign = -sign;
                    c = min(c, x / ten[i] % 10 - 1);
                }
                if (c < 0)
                    sign = 0;
                else
                    r += c * ten[i];
            }
            if (r < 0)
                continue;
            ans += d[r] * sign;
        }
        cout << ans << '\n';
    }
    return 0;
}