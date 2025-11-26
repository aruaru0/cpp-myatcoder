#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> as(11);
    rep(i, n) as[to_string(a[i]).size()].push_back(a[i]);

    ll ans = 0;
    ll ten = 1;
    rep(b, 11)
    {
        unordered_map<int, int> cnt;
        for (int na : as[b])
            cnt[na % m]++;
        rep(i, n)
        {
            ll r = (-ten * a[i] % m + m) % m;
            ans += cnt[r];
        }
        ten *= 10;
        ten %= m;
    }
    cout << ans << endl;
    return 0;
}