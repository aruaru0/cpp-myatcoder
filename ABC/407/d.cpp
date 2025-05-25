#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    vector<vector<bool>> flg(H, vector<bool>(W, false));
    auto f = [&](auto f, int h, int w, ll x) -> void
    {
        if (w == W)
        {
            w = 0;
            h++;
        }
        if (h == H)
        {
            ans = max(ans, x);
            return;
        }
        if (flg[h][w])
        {
            f(f, h, w + 1, x);
        }
        else
        {
            f(f, h, w + 1, x ^ A[h][w]);
            if (w + 1 < W && !flg[h][w + 1])
            {
                flg[h][w] = flg[h][w + 1] = true;
                f(f, h, w + 1, x);
                flg[h][w] = flg[h][w + 1] = false;
            }
            if (h + 1 < H && !flg[h + 1][w])
            {
                flg[h][w] = flg[h + 1][w] = true;
                f(f, h, w + 1, x);
                flg[h][w] = flg[h + 1][w] = false;
            }
        }
    };

    f(f, 0, 0, 0);

    cout << ans << endl;

    return 0;
}
