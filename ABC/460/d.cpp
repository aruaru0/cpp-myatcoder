#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[] = {0, -1, 0, 1, -1, 1, -1, 1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(ti, 2)
    {
        auto t = s;
        rep(i, h) rep(j, w)
        {
            s[i][j] = '.';
            if (t[i][j] == '.')
            {
                rep(v, 8)
                {
                    int ni = i + di[v], nj = j + dj[v];
                    if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                        continue;
                    if (t[ni][nj] == '#')
                        s[i][j] = '#';
                }
            }
        }
    }

    const int INF = 1001001001;
    queue<pair<int, int>> q;
    vector dist(h, vector<int>(w, INF));
    rep(i, h) rep(j, w) if (s[i][j] == '#')
    {
        dist[i][j] = 0;
        q.emplace(i, j);
    }
    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop();
        rep(v, 8)
        {
            int ni = i + di[v], nj = j + dj[v];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                continue;
            if (dist[ni][nj] != INF)
                continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.emplace(ni, nj);
        }
    }
    rep(i, h) rep(j, w) s[i][j] = "#."[dist[i][j] % 2];
    rep(i, h) cout << s[i] << endl;
    return 0;
}