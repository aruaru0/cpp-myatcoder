#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(i1, h) rep(j1, w)
    {
        if (s[i1][j1] == '#')
            continue;
        rep(i2, h) rep(j2, w)
        {
            if (s[i2][j2] == '#')
                continue;
            if (i1 == i2 && j1 == j2)
                continue;
            int cnt = 0;
            rep(i, h) rep(j, w)
            {
                if (s[i][j] == '#')
                    continue;
                bool humid = false;
                if (abs(i - i1) + abs(j - j1) <= d)
                    humid = true;
                if (abs(i - i2) + abs(j - j2) <= d)
                    humid = true;
                if (humid)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}