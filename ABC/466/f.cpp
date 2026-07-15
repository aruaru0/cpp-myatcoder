#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    priority_queue<pair<ll, ll>> q;
    q.emplace(x + 1, 1);
    rep(i, n)
    {
        ll num = 0;
        while (q.top().first > a[i])
        {
            auto [w, c] = q.top();
            q.pop();
            num += w / a[i] * c;
            q.emplace(w % a[i], c);
        }
        q.emplace(a[i], num);
    }

    ll ans = -1;
    while (q.size())
    {
        auto [w, c] = q.top();
        q.pop();
        if (w == 0)
            continue;
        ans += c;
    }
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}