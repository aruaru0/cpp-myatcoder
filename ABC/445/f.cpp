#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    using G = vector<vector<ll>>;
    G c(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> c[i][j];

    const ll INF = 1e18;

    auto mul = [&](const G &a, const G &b) -> G
    {
        G c(n, vector<ll>(n, INF));
        rep(i, n) rep(j, n) rep(k, n)
        {
            c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
        }
        return c;
    };

    G g(n, vector<ll>(n, INF));
    rep(i, n) g[i][i] = 0;
    while (k)
    {
        if (k & 1)
            g = mul(g, c);
        c = mul(c, c);
        k >>= 1;
    }
    rep(i, n) cout << g[i][i] << endl;
    return 0;
}