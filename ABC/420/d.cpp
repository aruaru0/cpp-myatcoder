#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pos = tuple<int, int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    rep(i, H)
    {
        cin >> s[i];
    }

    const int inf = 1e9;
    int sx, sy;
    int gx, gy;
    rep(i, H) rep(j, W)
    {
        if (s[i][j] == 'S')
        {
            sx = j;
            sy = i;
        }
        if (s[i][j] == 'G')
        {
            gx = j;
            gy = i;
        }
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, inf)));

    deque<Pos> q;
    q.push_back({sx, sy, 0});
    dist[sy][sx][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [cx, cy, cflg] = q.front();
        q.pop_front();
        rep(i, 4)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                continue;
            if (s[ny][nx] == '#')
                continue;
            int flg = cflg;
            if (s[ny][nx] == 'o' && flg == 1)
                continue;
            if (s[ny][nx] == 'x' && flg == 0)
                continue;
            if (s[ny][nx] == '?')
                flg ^= 1;

            if (dist[ny][nx][flg] > dist[cy][cx][cflg] + 1)
            {
                dist[ny][nx][flg] = dist[cy][cx][cflg] + 1;
                q.push_back({nx, ny, flg});
            }
        }
    }

    int ans = min(dist[gy][gx][0], dist[gy][gx][1]);
    if (ans != inf)
    {
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
