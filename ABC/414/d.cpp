#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = a[a.size() - 1] - a[0];

    if (m == 1)
    {
        cout << ans << endl;
        return 0;
    }

    vector<ll> d;
    rep(i, n - 1) d.push_back(a[i + 1] - a[i]);

    sort(d.begin(), d.end(), greater<ll>());

    rep(i, m - 1) ans -= d[i];

    cout << ans << endl;

    return 0;
}
