#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    ll tot, num;
    auto judge = [&](ll c)
    {
        tot = num = 0;
        rep(i, n)
        {
            ll k = ((c - 1) / p[i] + 1) / 2;
            if (k <= 0)
                continue;
            if (m / k / k / p[i] == 0)
                return false;
            tot += k * k * p[i];
            num += k;
            if (tot > m)
                return false;
        }
        return true;
    };

    ll ac = 1, wa = m + 1;
    while (ac + 1 < wa)
    {
        ll wj = (ac + wa) / 2;
        if (judge(wj))
            ac = wj;
        else
            wa = wj;
    }

    judge(ac);
    num += (m - tot) / ac;
    cout << num << endl;
    return 0;
}