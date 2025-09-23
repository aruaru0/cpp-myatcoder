#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 9;
    auto f = [&](auto f, int now) -> void
    {
        if (now >= ans)
            return;
        rep(i, h - 1) rep(j, w - 1)
        {
            int cnt = 0;
            rep(di, 2) rep(dj, 2) if (s[i + di][j + dj] == '#') cnt++;
            if (cnt == 4)
            {
                rep(di, 2) rep(dj, 2)
                {
                    s[i + di][j + dj] = '.';
                    f(f, now + 1);
                    s[i + di][j + dj] = '#';
                }
                return;
            }
        }

        ans = min(ans, now);
    };

    f(f, 0);
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(ti, t) solve();
    return 0;
}