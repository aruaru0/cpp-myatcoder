#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    map<char, vector<P>> mp;
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] != '.' && s[i][j] != '#')
                mp[s[i][j]].push_back({i, j});
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    deque<P> q;

    q.push_back({0, 0});
    dist[0][0] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    set<char> usedWarp;

    while (q.size())
    {
        auto [r, c] = q.front();
        q.pop_front();
        // cout << r << " " << c << endl;

        if (s[r][c] != '.' && usedWarp.find(s[r][c]) == usedWarp.end())
        {
            usedWarp.insert(s[r][c]);
            for (auto [nr, nc] : mp[s[r][c]])
            {
                if (dist[nr][nc] == -1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push_back({nr, nc});
                }
            }
        }
        rep(i, 4)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            if (s[nr][nc] == '#')
                continue;
            if (dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push_back({nr, nc});
            }
        }
    }

    cout << dist[h - 1][w - 1] << endl;

    return 0;
}
