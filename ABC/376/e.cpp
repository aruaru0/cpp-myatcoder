#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<P> ab(n);
    rep(i, n) cin >> ab[i].first;
    rep(i, n) cin >> ab[i].second;
    sort(ab.begin(), ab.end());

    ll ans = 1e18;

    ll sum = 0;
    priority_queue<int> q;
    for (auto [a, b] : ab)
    {
        if (q.size() >= k - 1)
        {
            ans = min(ans, (sum + b) * a);
        }
        sum += b;
        q.push(b);
        if (q.size() == k)
            sum -= q.top(), q.pop();
    }

    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}