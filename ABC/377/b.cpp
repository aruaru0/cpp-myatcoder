#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<string> s(8);
    rep(i, 8) cin >> s[i];

    vector<bool> h(8), w(8);

    rep(i, 8) rep(j, 8)
    {
        if (s[i][j] == '#')
        {
            h[i] = true;
            w[j] = true;
        }
    }

    int ans = 64;
    rep(i, 8) rep(j, 8) if (h[i] || w[j])
    {
        ans--;
    }

    cout << ans << endl;
    return 0;
}
