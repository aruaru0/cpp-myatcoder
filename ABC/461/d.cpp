#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto f = [&](int k) -> ll
    {
        if (k == -1)
            return 0;
        ll res = 0;
        rep(li, h)
        {
            vector<int> a(w);
            for (int ri = li; ri < h; ri++)
            {
                rep(j, w) a[j] += s[ri][j] - '0';

                int l = 0, sum = 0;
                rep(r, w)
                {
                    sum += a[r];
                    while (sum > k)
                    {
                        sum -= a[l];
                        l++;
                    }
                    res += r - l + 1;
                }
            }
        }
        return res;
    };
    ll ans = f(k) - f(k - 1);
    cout << ans << endl;
    return 0;
}