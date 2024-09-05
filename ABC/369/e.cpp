#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const ll inf = ll(1e18);
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), t(m);
    vector<vector<ll>> dp(n, vector<ll>(n, inf));

    rep(i, n) dp[i][i] = 0;

    rep(i, m)
    {
        cin >> u[i] >> v[i] >> t[i];
        u[i]--;
        v[i]--;
        chmin(dp[u[i]][v[i]], (ll)t[i]);
        chmin(dp[v[i]][u[i]], (ll)t[i]);
    }

    rep(k, n) rep(i, n) rep(j, n)
    {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int k;
        cin >> k;
        vector<int> b;
        rep(i, k)
        {
            int x;
            cin >> x;
            b.push_back(x - 1);
        }

        ll ans = inf;
        do
        {
            rep(bit, 1 << k)
            {
                ll cur = 0, cost = 0;
                rep(i, k)
                {
                    if ((bit >> i) % 2)
                    {
                        cost += dp[cur][u[b[i]]] + t[b[i]];
                        cur = v[b[i]];
                    }
                    else
                    {
                        cost += dp[cur][v[b[i]]] + t[b[i]];
                        cur = u[b[i]];
                    }
                }
                cost += dp[cur][n - 1];
                ans = min(ans, cost);
            }

        } while (next_permutation(b.begin(), b.end()));
        cout << ans << endl;
    }

    return 0;
}
