#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;

    auto f = [&](auto f, ll x, int idx, int cnt)
    {
        if (cnt == 0)
        {
            ans = max(ans, x);
            return;
        }
        if (idx == n)
            return;
        f(f, x ^ a[idx], idx + 1, cnt - 1);
        f(f, x, idx + 1, cnt);
    };

    if (k <= n - k)
    {
        f(f, 0, 0, k);
    }
    else
    {
        ll all = 0;
        for (auto e : a)
            all ^= e;
        f(f, all, 0, n - k);
    }
    cout << ans << endl;

    return 0;
}
