#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};

    vector<vector<int>> used(h, vector<int>(w, 0));
    vector<vector<int>> stop(h, vector<int>(w, 0));
    // 動けなくなる場所をマークする
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == '#')
        {
            stop[i][j] = 1;
            rep(k, 4)
            {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w)
                    continue;
                stop[ni][nj] = 1;
            }
        }
    }

    // 動ける場所の数を数える
    int counter, id = 0;
    auto dfs = [&](auto dfs, int i, int j)
    {
        used[i][j] = id;
        counter++;
        if (stop[i][j])
            return;
        rep(k, 4)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w)
                continue;
            if (s[ni][nj] == '#')
                continue;
            if (used[ni][nj] == id) // 現在の探索ですでに通過した部分をマークする
                continue;
            dfs(dfs, ni, nj);
        }
    };

    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#')
            {
                continue;
            }
            if (used[i][j] != 0)
            {
                continue;
            }
            counter = 0;
            id++; // 探索IDを更新する
            dfs(dfs, i, j);
            ans = max(ans, counter);
        }
    }

    cout << ans << endl;
    return 0;
}