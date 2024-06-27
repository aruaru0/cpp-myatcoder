#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using P = pair<ll, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    vector<ll> d(n, 1);

    priority_queue<P, vector<P>, greater<P>> pq;
    rep(i, n)
    {
        pq.emplace((2 * 2 - 1) * a[i], i);
        ans += a[i];
    }

    rep(ti, n - 2)
    {
        auto [dif, i] = pq.top();
        pq.pop();
        ans += dif;
        d[i]++;
        pq.emplace(
            a[i] * ((d[i] + 1) * (d[i] + 1) - d[i] * d[i]), i);
    }

    cout << ans << endl;
}
