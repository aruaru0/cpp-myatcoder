#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct P
{
    ll r, c;
};

const ll INF = 1e18;
// ax+b = cx+d
ll calc(ll a, ll b, ll c, ll d)
{
    if (a == c)
        return (b == d) ? INF : -1;
    a -= c;
    d -= b;
    if (a < 0)
        a = -a, d = -d;
    if (d % a != 0)
        return -1;
    return d / a;
}

int main()
{
    P t, a;
    cin >> t.r >> t.c >> a.r >> a.c;
    ll n;
    int m, l;

    cin >> n >> m >> l;
    vector<pair<char, ll>> pt, pa;
    rep(_, 2)
    {
        ll now = 0;
        rep(i, m)
        {
            char s;
            ll a;
            cin >> s >> a;
            now += a;
            pt.emplace_back(s, now);
        }
        swap(pt, pa);
        swap(m, l);
    }

    map<char, P> mp;
    mp['U'] = P(-1, 0);
    mp['D'] = P(1, 0);
    mp['L'] = P(0, -1);
    mp['R'] = P(0, 1);

    ll ans = 0;
    ll now = 0;
    int ti = 0, ai = 0;
    while (ti < m && ai < l)
    {
        ll nxt = min(pt[ti].second, pa[ai].second);

        ll w = nxt - now;
        P dt = mp[pt[ti].first];
        P da = mp[pa[ai].first];

        {
            ll rx = calc(dt.r, t.r, da.r, a.r);
            ll cx = calc(dt.c, t.c, da.c, a.c);

            if (rx != -1 && cx != -1)
            {
                if (rx == INF)
                    swap(rx, cx);
                if (rx == INF)
                {
                    ans += w;
                }
                else if (cx == INF)
                {
                    if (0 < rx && rx <= w)
                        ans += 1;
                }
                else
                {
                    if (rx == cx && 0 < rx && rx <= w)
                        ans += 1;
                }
            }
        }

        t.r += dt.r * w;
        t.c += dt.c * w;
        a.r += da.r * w;
        a.c += da.c * w;
        if (nxt == pt[ti].second)
            ti++;
        if (nxt == pa[ai].second)
            ai++;
        now = nxt;
    }
    cout << ans << endl;
    return 0;
}