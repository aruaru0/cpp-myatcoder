#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int m = 25;
    vector<ll> d(m);
    rep(k, m)
    {
        int mod = 2 << k;
        vector<ll> sum(mod), cnt(mod);
        ll now = 0;
        rep(i, n)
        {
            sum[a[i] % mod] += a[i];
            cnt[a[i] % mod]++;
            int b = (mod + ((1 << k) - a[i]) % mod) % mod;
            now += sum[b];
            now += cnt[b] * a[i];
        }
        d[k] = now;
    }

    ll ans = 0;
    rep(k, m) ans += d[k] >> k;
    cout << ans << endl;
    return 0;
}