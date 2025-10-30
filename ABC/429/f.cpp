#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1001001001;

using A = array<int, 3>;
using S = array<A, 3>;
const S inf = {A({INF, INF, INF}), A({INF, INF, INF}), A({INF, INF, INF})};
S op(S a, S b)
{
    S c = inf;
    rep(i, 3) rep(j, 3) rep(k, 3) c[i][k] = min(c[i][k], a[i][j] + b[j][k]);
    return c;
}
S e()
{
    return S({A({0, INF, INF}), A({INF, 0, INF}), A({INF, INF, 0})});
}
S toS(const string &s)
{
    S a = inf;
    rep(i, 3) rep(j, 3) a[i][j] = abs(i - j);
    rep(k, 3) if (s[k] == '#')
    {
        rep(i, k + 1) for (int j = k; j < 3; j++)
        {
            a[i][j] = a[j][i] = INF;
        }
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n, "...");
    {
        vector<string> S(3);
        rep(i, 3) cin >> S[i];
        rep(i, 3) rep(j, n) s[j][i] = S[i][j];
    }

    segtree<S, op, e> t(n);
    rep(i, n) t.set(i, toS(s[i]));

    int q;
    cin >> q;
    rep(qi, q)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        s[c][r] ^= '.' ^ '#';
        t.set(c, toS(s[c]));

        S a = t.all_prod();
        int ans = a[0][2] + n - 1;
        if (ans >= INF)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}