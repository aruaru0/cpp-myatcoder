#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll calc(vector<vector<vector<ll>>> &S, int lx, int rx, int ly, int ry, int lz, int rz)
{
    // int n = S.size();
    // rep(x, n)
    // {
    //     rep(y, n)
    //     {
    //         rep(z, n)
    //         {
    //             cout << S[x][y][z] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    ll total = S[rx][ry][rz];
    total -= S[lx - 1][ry][rz];
    total -= S[rx][ly - 1][rz];
    total -= S[rx][ry][lz - 1];
    total += S[lx - 1][ly - 1][rz];
    total += S[lx - 1][ry][lz - 1];
    total += S[rx][ly - 1][lz - 1];
    total -= S[lx - 1][ly - 1][lz - 1];
    return total;
}

int main()
{
    int n;
    cin >> n;
    // nxnxnの配列を作る
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n)));
    vector<vector<vector<ll>>> S(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    rep(i, n) rep(j, n) rep(k, n) cin >> a[i][j][k];

    rep(x, n) rep(y, n) rep(z, n)
        S[x + 1][y + 1][z + 1] += S[x + 1][y + 1][z] + a[x][y][z];

    rep(x, n + 1) rep(y, n) rep(z, n + 1)
        S[x][y + 1][z] += S[x][y][z];

    rep(x, n) rep(y, n + 1) rep(z, n + 1)
        S[x + 1][y][z] += S[x][y][z];

    int q;
    cin >> q;
    rep(qi, q)
    {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll ans = calc(S, lx, rx, ly, ry, lz, rz);
        cout << ans << endl;
    }

    return 0;
}
