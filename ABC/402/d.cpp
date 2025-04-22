#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<int> grp(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int g = (u + v) % n;
        grp[g]++;
    }

    ll ans = m * (m - 1) / 2;
    rep(i, n)
    {
        ans -= (ll)grp[i] * (grp[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
