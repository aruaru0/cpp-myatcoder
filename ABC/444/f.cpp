#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll h = (n + m) / 2 + 1;

    const int INF = 1001001001;
    auto f = [&](int x) -> bool
    {
        {
            int big = 0;
            rep(i, n) if (a[i] >= x) big++;
            if (big + m < h)
                return false;
        }

        ll one = 0, big = 0;
        map<int, ll> mp;
        auto add = [&](int len, ll num)
        {
            if (len < x)
                one += len * num;
            else
                mp[len] += num, big += num;
        };
        auto cut = [&](int len, ll num)
        {
            mp[len] -= num;
            if (mp[len] == 0)
                mp.erase(len);
            big -= num;
            add(len / 2, num);
            add(len - len / 2, num);
        };

        rep(i, n)
        {
            int len = a[i], num = 1;
            while ((len + 1) / 2 >= x)
                len /= 2, num *= 2;
            ll r = a[i] - len * num, l = num - r;
            add(len, l);
            if (r)
            {
                add(len + 1, r);
                if (len + 1 == x * 2 - 1)
                    cut(len + 1, r);
            }
        }
        if (big < h)
            return false;

        while (big > h)
        {
            auto [len, num] = *mp.rbegin();
            cut(len, min(num, big - h));
        }
        return one + big >= n + m;
    };

    int ac = 1, wa = INF;
    while (ac + 1 < wa)
    {
        int wj = (ac + wa) / 2;
        if (f(wj))
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}