#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> m;
    rep(i, n) m[a[i]]++;
    vector<ll> b;
    for (auto e : m)
    {
        b.push_back(e.first);
    }
    ll idx = 0;
    for (auto e : b)
    {
        m[e] = idx;
        idx++;
    }

    // for (auto e : m)
    // {
    //     cout << e.first << " " << e.second << endl;
    // }
    fenwick_tree<ll> val(m.size() + 1), cnt(m.size() + 1);
    ll ans = 0;
    rep(i, n)
    {
        int x = m[a[i]];
        val.add(x, a[i]);
        cnt.add(x, 1);
        ans += (ll)a[i] * cnt.sum(0, x) - val.sum(0, x);
    }

    cout << ans << endl;
}