#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct Machine
{
    int a, p;
};

// 回答を写経
int main()
{
    int n, x;
    cin >> n >> x;
    vector<Machine> s(n), t(n);
    rep(i, n)
    {
        cin >> s[i].a >> s[i].p;
        cin >> t[i].a >> t[i].p;

        if (t[i].a * s[i].p > s[i].a * t[i].p)
        {
            swap(s[i], t[i]);
        }
    }

    auto f = [&](int m)
    {
        ll cost = 0;
        rep(i, n)
        {
            ll now = 1e18;
            rep(j, s[i].a)
            {
                int k = max(m - t[i].a * j, 0);
                k = (k + s[i].a - 1) / s[i].a;
                now = min(now, t[i].p * j + (ll)s[i].p * k);
            }
            cost += now;
            if (cost > x)
                return false;
        }
        return true;
    };

    int ac = 0, wa = x * 100 + 1;
    while (ac + 1 < wa)
    {
        int wj = (ac + wa) / 2;
        if (f(wj))
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << endl;
    return 0;
}