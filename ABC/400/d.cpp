#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    --si;
    --sj;
    --ti;
    --tj;

    const int INF = 1001001001;
    vector dist(h, vector<int>(w, INF));
    vector used(h, vector<bool>(w));
    deque<pair<int, int>> q;

    auto push = [&](int i, int j, int d, int cost)
    {
        if (dist[i][j] <= d)
            return;
        dist[i][j] = d;
        if (cost == 0)
            q.emplace_front(i, j);
        else
            q.emplace_back(i, j);
    };
    push(si, sj, 0, 0);

    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop_front();
        if (used[i][j])
            continue;
        used[i][j] = true;
        int d = dist[i][j];
        rep(v, 4)
        {
            int ni = i + di[v], nj = j + dj[v];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                continue;
            if (s[ni][nj] == '.')
                push(ni, nj, d, 0);
        }
        rep(v, 4)
        {
            int ni = i, nj = j;
            rep(k, 2)
            {
                ni += di[v];
                nj += dj[v];
                if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                    break;
                push(ni, nj, d + 1, 1);
            }
        }
    }

    int ans = dist[ti][tj];
    cout << ans << endl;
    return 0;
}