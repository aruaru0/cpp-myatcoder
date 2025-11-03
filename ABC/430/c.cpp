#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    vector<int> sa(n + 1), sb(n + 1);
    rep(i, n)
    {
        if (s[i] == 'a')
            sa[i + 1] = 1;
        else
            sb[i + 1] = 1;
    }
    rep(i, n) sa[i + 1] += sa[i];
    rep(i, n) sb[i + 1] += sb[i];

    ll ans = 0;
    rep(l, n)
    {
        int ra, rb;
        {
            int wa = l, ac = n + 1;
            while (ac - wa > 1)
            {
                int wj = (wa + ac) / 2;
                if (sa[wj] - sa[l] >= a)
                    ac = wj;
                else
                    wa = wj;
            }
            ra = ac;
        }
        {
            int ac = l, wa = n + 1;
            while (wa - ac > 1)
            {
                int wj = (wa + ac) / 2;
                if (sb[wj] - sb[l] < b)
                    ac = wj;
                else
                    wa = wj;
            }
            rb = wa;
        }
        ans += max(0, rb - ra);
    }

    cout << ans << endl;
    return 0;
}