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
    rep(i, h)
    {
        cin >> s[i];
    }

    vector<vector<int>> d(h, vector<int>(w, 0));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    auto dfs = [&](auto dfs, int y, int x, int cnt) -> bool
    {
        bool flg = false;
        if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
            flg = true;

        d[y][x] = cnt;

        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (s[ny][nx] == '#')
                continue;
            if (d[ny][nx] != 0)
                continue;
            bool ret = dfs(dfs, ny, nx, cnt + 1);
            flg |= ret;
        }
        return flg;
    };

    int idx = 1;
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#')
                continue;
            if (d[i][j] != 0)
                continue;
            bool ret = dfs(dfs, i, j, idx);
            idx++;
            if (!ret)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
