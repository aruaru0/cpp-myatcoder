#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n + 1);
    rep(i, n)
    {
        cin >> a[i];
        b[i + 1] = (b[i] + a[i]) % m;
    }

    fenwick_tree<ll> bit(m);
    ll s = 0, ans = 0;
    rep(r, n + 1)
    {
        ans += (ll)b[r] * r - (ll)s + bit.sum(b[r] + 1, m) * m;
        s += b[r];
        bit.add(b[r], 1);
    }

    cout << ans << endl;
    return 0;
}
