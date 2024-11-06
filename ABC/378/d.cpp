#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<bool>> used(h, vector<bool>(w, false));
    auto dfs = [&](auto f, int y, int x, int cnt) -> int
    {
        if (cnt == k)
        {
            return 1;
        }
        used[y][x] = true;

        int ret = 0;
        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (used[ny][nx] || s[ny][nx] == '#')
                continue;
            ret += f(f, ny, nx, cnt + 1);
        }
        used[y][x] = false;

        return ret;
    };

    int ans = 0;
    rep(y, h)
    {
        rep(x, w)
        {
            if (s[y][x] == '#')
                continue;
            ans += dfs(dfs, y, x, 0);
        }
    }

    cout << ans << endl;

    return 0;
}
