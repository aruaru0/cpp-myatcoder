// 正解を写経
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct P
{
    ll x, y;
    P(ll x = 0, ll y = 0) : x(x), y(y) {}
};

int main()
{
    ll k;
    cin >> k;
    P s, t;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;

    ll ans = abs(s.x - t.x) + abs(s.y - t.y);
    rep(sv, 4) rep(tv, 4)
    {
        ll now = 0;
        auto toBig = [&](P p, int v)
        {
            P bp(p.x / k, p.y / k);
            P sp(p.x % k, p.y % k);
            if ((bp.x + bp.y) % 2 == 0)
            {
                if (v == 0)
                    bp.y++, now += k - sp.y;
                if (v == 1)
                    bp.y--, now += sp.y + 1;
                if (v == 2)
                    bp.x++, now += k - sp.x;
                if (v == 3)
                    bp.x--, now += sp.x + 1;
            }
            return bp;
        };
        P bs = toBig(s, sv), bt = toBig(t, tv);
        P d(bt.x - bs.x, bt.y - bs.y);
        d.x = abs(d.x);
        d.y = abs(d.y);
        if (d.x < d.y)
            swap(d.x, d.y);
        if (k == 1)
            now += d.x + d.y;
        else if (k == 2)
        {
            now += d.y * 2;
            now += (d.x - d.y) / 2 * 3;
        }
        else
            now += d.x * 2;
        ans = min(ans, now);
    }

    cout << ans << endl;
    return 0;
}