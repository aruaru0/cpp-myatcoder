#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

const int M = 60;
mint dp[M + 1][2][2][M + 1];

void solve()
{
    ll n, k;
    cin >> n >> k;
    n++;
    rep(i, M + 1) rep(j, 2) rep(s, 2) rep(p, k + 1) dp[i][j][s][p] = 0;
    dp[M][0][0][0] = 1;
    for (int i = M - 1; i >= 0; i--)
    {
        rep(j, 2) rep(s, 2) rep(p, k + 1)
        {
            mint now = dp[i + 1][j][s][p];
            if (now == 0)
                continue;
            rep(a, 2)
            {
                int ns = s, np = p + a;
                if (s == 0)
                {
                    if (a < (n >> i & 1))
                        ns = 1;
                    if (a > (n >> i & 1))
                        continue;
                }
                if (np > k)
                    continue;
                dp[i][j][ns][np] += now;
                if (j == 0 && a)
                    dp[i][1][ns][np] += now * (1ll << i);
            }
        }
    }
    mint ans = dp[0][1][1][k];
    cout << ans.val() << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}