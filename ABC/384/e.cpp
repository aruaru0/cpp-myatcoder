#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<ll, int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int H, W, X;
    cin >> H >> W >> X;
    int P, Q;
    cin >> P >> Q;
    P--;
    Q--;
    vector<vector<ll>> s(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> s[i][j];

    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<bool>> seen(H, vector<bool>(W, false));

    ll ans = s[P][Q];
    seen[P][Q] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    rep(i, 4)
    {
        int px = Q + dx[i];
        int py = P + dy[i];
        if (px < 0 || px >= W || py < 0 || py >= H)
            continue;
        seen[py][px] = true;
        pq.push(T{s[py][px], py, px});
    }

    const ll inf = 1e18;

    while (!pq.empty())
    {
        auto [c, cy, cx] = pq.top();
        pq.pop();
        // cout << c << " " << cy << " " << cx << endl;
        if (c > inf / X)
        {
            break;
        }
        if (ans <= c * X)
        {
            break;
        }
        ans += c;
        rep(i, 4)
        {
            int px = cx + dx[i];
            int py = cy + dy[i];
            if (px < 0 || px >= W || py < 0 || py >= H)
                continue;
            if (seen[py][px])
                continue;
            seen[py][px] = true;
            pq.push(T{s[py][px], py, px});
        }
    }

    cout << ans << endl;

    return 0;
}
