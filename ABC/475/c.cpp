#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, s, L;
    cin >> n >> s >> L;
    s--;
    vector<ll> a(n - 1);
    for (auto &e : a)
        cin >> e;
    int ans = 1;
    vector<ll> p(n);
    for (int i = 0; i < n - 1; i++)
        p[i + 1] = p[i] + a[i];
    for (int l = 0; l <= s; l++)
    {
        for (int r = s; r < n; r++)
        {
            ll x = p[s] - p[l], y = p[r] - p[s];
            if (min(2 * x + y, x + 2 * y) <= L)
                ans = max(ans, r - l + 1);
        }
    }
    cout << ans << '\n';
}
