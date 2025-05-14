#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int inf = 1e7;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    vector<vector<int>> dirc(h, vector<int>(w, -1));

    queue<P> q;
    rep(r, h) rep(c, w)
    {
        if (s[r][c] == 'E')
        {
            dist[r][c] = 0;
            q.push(P(r, c));
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    string arrow = "v^><";

    while (!q.empty())
    {
        auto [cr, cc] = q.front();
        q.pop();
        rep(i, 4)
        {
            int pr = cr + dr[i];
            int pc = cc + dc[i];
            if (pr < 0 || pc < 0 || pr >= h || pc >= w)
                continue;
            if (s[pr][pc] == '#')
                continue;
            if (dist[pr][pc] > dist[cr][cc] + 1)
            {
                dist[pr][pc] = dist[cr][cc] + 1;
                dirc[pr][pc] = i;
                q.push(P(pr, pc));
            }
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '.')
            {
                cout << arrow[dirc[i][j]];
            }
            else
            {
                cout << s[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
