#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int sx, sy, gx, gy;
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == 'S')
            sx = i, sy = j;
        if (s[i][j] == 'G')
            gx = i, gy = j;
    }

    const int inf = 1e9;
    vector<vector<vector<int>>> dist(h, vector(w, vector<int>(2, inf)));
    dist[sx][sy][0] = 0;
    dist[sx][sy][1] = 0;
    deque<T> q;
    q.emplace_back(sx, sy, 0);
    q.emplace_back(sx, sy, 1);

    int dx[][2] = {{-1, 1}, {0, 0}};
    int dy[][2] = {{0, 0}, {-1, 1}};

    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop_front();
        int nd = d == 0 ? 1 : 0;
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[nd][i];
            int ny = y + dy[nd][i];
            if (nx < 0 || h <= nx || ny < 0 || w <= ny)
                continue;
            if (s[nx][ny] == '#')
                continue;

            if (dist[nx][ny][nd] == inf)
            {
                dist[nx][ny][nd] = dist[x][y][d] + 1;
                q.emplace_back(nx, ny, nd);
            }
        }
    }

    int ans = min(dist[gx][gy][0], dist[gx][gy][1]);
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
