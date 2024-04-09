#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using PP = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    int stx = 0, sty = 0;
    int gtx = 0, gty = 0;
    rep(i, h) rep(j, w)
    {
        if (a[i][j] == 'S')
        {
            stx = j;
            sty = i;
        }
        if (a[i][j] == 'T')
        {
            gtx = j;
            gty = i;
        }
    }
    int N;
    cin >> N;
    vector<int> r(N), c(N), e(N);
    int start = -1;
    rep(i, N)
    {
        cin >> r[i] >> c[i] >> e[i];
        r[i]--;
        c[i]--;
        if (r[i] == sty && c[i] == stx)
        {
            start = i;
        }
    }
    if (start == -1)
    {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> node(N + 1);
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    auto solve = [&](int ni)
    {
        queue<PP> q;
        int sx, sy;
        sx = c[ni];
        sy = r[ni];
        q.push(PP{sy, sx});
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[sy][sx] = 0;
        while (q.size() != 0)
        {
            PP cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.second + dx[i];
                int ny = cur.first + dy[i];
                // cout << cur.first << " " << cur.second << "->";
                // cout << " " << ny << " " << nx << endl;

                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                {
                    continue;
                }
                if (dist[ny][nx] != -1)
                {
                    continue;
                }
                if (a[ny][nx] == '#')
                {
                    continue;
                }

                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                // cout << cur.first << " " << cur.second << "-->";
                // cout << nx << " " << ny << " " << dist[ny][nx] << endl;
                q.push({ny, nx});
            }
        }

        // cout << "------------" << endl;
        // rep(i, h)
        // {
        //     rep(j, w)
        //     {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        rep(i, N)
        {
            if (i == ni)
            {
                continue;
            }
            // cout << e[ni] << " " << dist[r[i]][c[i]] << endl;
            if (dist[r[i]][c[i]] != -1 && dist[r[i]][c[i]] <= e[ni])
            {
                node[ni].push_back(i);
            }
        }
        if (dist[gty][gtx] != -1 && dist[gty][gtx] <= e[ni])
        {
            node[ni].push_back(N);
        }
    };

    rep(ni, N)
    {
        solve(ni);
    }

    // rep(i, N)
    // {
    //     cout << "[";
    //     for (auto e : node[i])
    //     {
    //         cout << e << " ";
    //     }
    //     cout << ']' << endl;
    // }

    vector<bool> used(N + 1);
    function<bool(int)> dfs = [&](int v) -> bool
    {
        if (v == N)
        {
            return true;
        }
        used[v] = true;
        for (auto e : node[v])
        {
            if (used[e])
            {
                continue;
            }
            if (dfs(e) == true)
            {
                return true;
            }
        }
        return false;
    };

    if (dfs(start) == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}