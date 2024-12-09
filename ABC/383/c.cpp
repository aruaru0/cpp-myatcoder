#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int inf = 1e9;
    vector<vector<int>> dist(h, vector<int>(w, inf));

    deque<P> q;
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == 'H')
        {
            dist[i][j] = 0;
            q.push_back({i, j});
        }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop_front();

        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (s[ny][nx] == '#')
                continue;
            if (dist[ny][nx] <= dist[y][x] + 1)
                continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push_back({ny, nx});
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w)
    {
        if (dist[i][j] <= d)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
