#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    auto rotate = [&](vector<string> s) -> vector<string>
    {
        vector<string> ret(n, string(n, '.'));
        rep(i, n) rep(j, n)
            ret[j][n - 1 - i] = s[i][j];
        return ret;
    };

    int ans = n * n;
    rep(k, 4)
    {
        int cnt = k;
        rep(i, n) rep(j, n) if (s[i][j] != t[i][j]) cnt++;
        ans = min(ans, cnt);
        s = rotate(s);
    }

    cout << ans << endl;

    return 0;
}
