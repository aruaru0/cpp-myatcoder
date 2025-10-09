#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll op(ll a, ll b) { return min(a, b); }
ll e() { return 1e18; }
ll mapping(ll f, ll x) { return x - f; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    lazy_segtree<ll, op, e, ll, mapping, composition, id> rem(a);
    fenwick_tree<int> sold(n);

    int q;
    cin >> q;
    rep(qi, q)
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l;

        ll ans = ll(r - l - sold.sum(l, r)) * k;
        rem.apply(l, r, k);
        while (1)
        {
            auto f = [&](ll x)
            { return x >= 0; };
            int i = rem.max_right(l, f);
            if (i >= r)
                break;
            ans += rem.get(i);
            rem.set(i, e());
            sold.add(i, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}