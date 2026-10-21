#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (int l = 3; l <= 19; l++)
    {
        for (ll a = 1;; a++)
        {
            {
                ll m = n;
                rep(i, l) m /= a + i;
                if (m == 0)
                    break;
            }
            ll ac = 1, wa = 1e9;
            auto judge = [&](ll d)
            {
                ll m = n;
                rep(i, l) m /= a + d * i;
                return m >= 1;
            };
            while (ac + 1 < wa)
            {
                ll wj = (ac + wa) / 2;
                if (judge(wj))
                    ac = wj;
                else
                    wa = wj;
            }
            ans += ac;
        }
    }
    cout << ans << endl;
    return 0;
}