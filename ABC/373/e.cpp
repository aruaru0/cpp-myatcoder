#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    if (n == m)
    {
        rep(i, n) cout << 0 << ' ';
        cout << endl;
        return 0;
    }

    vector<ll> a = A;
    sort(a.begin(), a.end());
    vector<ll> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];

    ll remain = k;
    rep(i, n) remain -= a[i];

    map<int, ll> ans;
    rep(i, n)
    {
        auto judge = [&](ll x)
        {
            ll y = a[i] + x;
            int r = upper_bound(a.begin(), a.end(), y + 1) - a.begin();
            int l = n - m;
            if (r < l)
                return false;
            ll need = (y + 1) * (r - l) - (s[r] - s[l]);
            if (l <= i && i < r)
            {
                need += a[i];
                need -= a[l - 1];
            }
            return need > remain - x;
        };

        ll ac = remain + 1, wa = -1;
        while (ac - wa > 1)
        {
            ll wj = (ac + wa) / 2;
            if (judge(wj))
                ac = wj;
            else
                wa = wj;
        }

        if (ac == remain + 1)
            ac = -1;
        ans[a[i]] = ac;
    }

    rep(i, n) cout << ans[A[i]] << ' ';
    cout << endl;
    return 0;
}