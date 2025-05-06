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

    vector<ll> c(n);
    rep(i, n) cin >> c[i];

    vector<vector<int>> view(n);
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int x;
            cin >> x;
            x--;
            view[x].push_back(i);
        }
    }

    int bn = 1;
    rep(i, n) bn *= 3;

    ll ans = 1e18;

    rep(bit, bn)
    {
        vector<int> cnt(m);
        int b = bit;
        ll cost = 0;
        rep(i, n)
        {
            int t = b % 3;
            for (auto e : view[i])
                cnt[e] += t;
            cost += c[i] * t;
            b /= 3;
        }
        bool ok = true;
        for (auto e : cnt)
            if (e < 2)
                ok = false;
        if (ok)
            ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}
