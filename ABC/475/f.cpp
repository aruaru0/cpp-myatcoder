#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    if (h > w)
    {
        swap(h, w);
        vector<string> t(h);
        rep(i, h) rep(j, w) t[i] += s[j][i];
        swap(s, t);
    }

    ll ans = 1;
    rep(li, h)
    {
        vector<int> a(w);
        for (int ri = li; ri < h; ri++)
        {
            rep(j, w) a[j] |= s[ri][j] == '.';

            int lj = 0, num = 0;
            int lx = 0, rx = 0;
            rep(rj, w)
            {
                if (s[li][rj] == '.')
                    lx++;
                if (s[ri][rj] == '.')
                    rx++;
                while (lx && rx)
                {
                    if (s[li][lj] == '.')
                        lx--;
                    if (s[ri][lj] == '.')
                        rx--;
                    num += a[lj];
                    lj++;
                }
                if (a[rj])
                    ans += num;
            }
        }
    }
    cout << ans << endl;
    return 0;
}