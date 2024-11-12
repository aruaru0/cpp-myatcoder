#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> stones(m);
    rep(i, m) cin >> stones[i].first;
    rep(i, m) cin >> stones[i].second;
    sort(stones.begin(), stones.end());
    stones.emplace_back(n + 1, 0);

    for (auto [a, b] : stones)
    {
        cout << a << " " << b << endl;
    }

    ll sum = 0;

    int px = 0;
    ll num = 1;
    for (auto [x, a] : stones)
    {
        ll L = x - px;
        ll carry = num - L;
        if (carry < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        sum += (ll)x * a;

        px = x;
        num = carry + a;
    }

    ll ans = ll(n + 1) * n / 2 - sum;

    if (num != 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}