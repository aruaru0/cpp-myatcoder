#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * 2);
    rep(i, n * 2) cin >> a[i];

    ll ans = a[0];
    priority_queue<int> q;
    for (int i = 1; i < n * 2 - 1; i += 2)
    {
        q.push(a[i]);
        q.push(a[i + 1]);
        ans += q.top();
        q.pop();
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