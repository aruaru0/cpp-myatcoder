#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> p(n + 1), pmax(n + 1), pmin(n + 1);
    rep(i, n) p[i + 1] = p[i] + a[i];

    rep(i, n)
    {
        pmin[i + 1] = min(pmin[i], p[i + 1]);
        pmax[i + 1] = max(pmax[i], p[i + 1]);
    }

    const ll inf = 1e18;
    vector<ll> rmax(n + 2), rmin(n + 2);
    rmax[n + 1] = -inf;
    rmin[n + 1] = inf;
    for (int i = n; i >= 0; i--)
    {
        rmin[i] = min(p[i], rmin[i + 1]);
        rmax[i] = max(p[i], rmax[i + 1]);
    }

    ll ans = pmax[n] - pmin[n] + 1;

    for (int i = 1; i <= n; i++)
    {
        ll d = 2 * a[i - 1];
        ll lo = min(pmin[i - 1], rmin[i] - d);
        ll hi = max(pmax[i - 1], rmax[i] - d);
        ans = max(ans, hi - lo + 1);
    }

    cout << ans << endl;
    return 0;
}