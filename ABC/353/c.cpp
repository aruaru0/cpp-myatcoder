#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    for (auto e : a)
    {
        ans += ll(e) * ll(n - 1);
    }

    ll r = n;
    ll cnt = 0;
    rep(i, n)
    {
        r = max(r, ll(i + 1));
        while (r - 1 > i && a[r - 1] + a[i] >= 100000000)
            r--;
        cnt += n - r;
    }
    ans -= cnt * 100000000;
    cout << ans << endl;
}