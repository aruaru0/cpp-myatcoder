#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i, m) cin >> p[i].first >> p[i].second;

    // p[i].first - p[i].second順にソート
    sort(p.begin(), p.end(), [](P a, P b)
         { return a.first - a.second < b.first - b.second; });

    ll ans = 0;
    ll x = n;
    for (auto [a, b] : p)
    {
        if (x >= a)
        {
            ll cost = a - b;
            ll n = (x - a) / cost + 1;
            ans += n;
            x -= n * cost;
        }
    }

    cout << ans << endl;

    return 0;
}
