#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void chmin(ll &a, ll b) { a = min(a, b); }

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> d(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> d[i];

    vector<ll> sa(n + 1);
    rep(i, n) sa[i + 1] = sa[i] + a[i];

    rep(k, 2)
    {
        rep(i, n) chmin(d[(i + 1) % n], d[i] + a[i]);
        for (int i = n - 1; i >= 0; i--)
        {
            chmin(d[i], d[(i + 1) % n] + a[i]);
        }
    }

    rep(qi, q)
    {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        if (s > t)
            swap(s, t);
        ll ans = 0;
        if (t == n)
        {
            ans = d[s];
        }
        else
        {
            ans = d[s] + d[t];
            ll sum = sa[t] - sa[s];
            chmin(ans, sum);
            chmin(ans, sa[n] - sum);
        }
        cout << ans << '\n';
    }
    return 0;
}