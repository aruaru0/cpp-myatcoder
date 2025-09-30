#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint;

const int M = 5000;
mint C[M + 1][M + 1];

void solve()
{
    int n;
    cin >> n;
    int s = 0;
    mint ans = 1;
    rep(i, n)
    {
        int c;
        cin >> c;
        s += c;
        ans *= C[s][c];
    }
    cout << ans.val() << '\n';
}

int main()
{
    int T, mod;
    cin >> T >> mod;
    mint::set_mod(mod);
    C[0][0] = 1;
    rep(i, M) rep(j, i + 1)
    {
        C[i + 1][j] += C[i][j];
        C[i + 1][j + 1] += C[i][j];
    }

    rep(ti, T) solve();
    return 0;
}