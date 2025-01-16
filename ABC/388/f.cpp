#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

bool solve()
{
    ll n;
    int m, a, b;
    cin >> n >> m >> a >> b;
    vector<ll> l(m), r(m);
    rep(i, m) cin >> l[i] >> r[i];
    rep(i, m) l[i]--;

    if (a == b)
    {
        rep(i, m)
        {
            ll x = (r[i] - 1) / a * a;
            if (l[i] <= x)
                return false;
        }
        if ((n - 1) % a)
            return false;
        return true;
    }

    vector<int> dp(b);
    dp[0] = 1;
    ll i = 0;

    l.push_back(n);
    r.push_back(n);
    m++;
    rep(j, m)
    {
        ll w = l[j] - i - 1;
        if (w > a * a)
        {
            if (dp == vector<int>(b, 0))
                return false;
            dp = vector<int>(b, 1);
        }
        else
        {
            rep(k, w)
            {
                dp.insert(dp.begin(), 0);
                for (int x = a; x <= b; x++)
                    dp[0] |= dp[x];
                dp.pop_back();
            }
        }

        w = r[j] - l[j];
        if (w >= b)
            return false;
        rep(k, w)
        {
            dp.insert(dp.begin(), 0);
            dp.pop_back();
        }

        i = r[j] - 1;
    }

    return dp[0] == 1;
}

int main()
{
    if (solve())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}