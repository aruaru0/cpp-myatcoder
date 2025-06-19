#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    if (h > w)
    {
        swap(h, w);
        vector<string> old(h, string(w, '.'));
        swap(old, s);
        rep(i, h) rep(j, w) s[i][j] = old[j][i];
    }

    int n = h * w;
    vector<int> cnt(n * 2 + 1);

    ll ans = 0;
    rep(si, h)
    {
        vector<int> a(w);
        for (int ti = si; ti < h; ti++)
        {
            rep(j, w) a[j] += s[ti][j] == '#' ? 1 : -1;
            vector<int> sum(w + 1);
            sum[0] = n;
            rep(j, w) sum[j + 1] = sum[j] + a[j];
            rep(j, w)
            {
                cnt[sum[j]]++;
                ans += cnt[sum[j + 1]];
            }
            rep(j, w) cnt[sum[j]] = 0;
        }
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}