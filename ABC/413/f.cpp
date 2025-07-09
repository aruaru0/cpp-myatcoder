#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    const int INF = 1001001001;
    vector dist(h, vector<int>(w, INF));
    vector checked(h, vector<bool>(w));
    queue<pair<int, int>> q;
    rep(i, k)
    {
        int r, c;
        cin >> r >> c;
        --r;
        --c;
        dist[r][c] = 0;
        q.emplace(r, c);
    }

    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop();
        rep(v, 4)
        {
            int ni = i + di[v], nj = j + dj[v];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                continue;
            if (dist[ni][nj] != INF)
                continue;
            if (checked[ni][nj])
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
            }
            else
            {
                checked[ni][nj] = true;
            }
        }
    }

    ll ans = 0;
    rep(i, h) rep(j, w) if (dist[i][j] != INF) ans += dist[i][j];
    cout << ans << endl;
    return 0;
}