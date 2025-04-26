#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e8;

struct Status
{
    int x, y;
    ll st;
    bool operator==(const Status &other) const
    {
        return x == other.x && y == other.y && st == other.st;
    }
};

// ハッシュ関数を定義してunordered_mapでStatusを使えるようにする
namespace std
{
    template <>
    struct hash<Status>
    {
        size_t operator()(const Status &s) const
        {
            return ((hash<int>()(s.x) ^ (hash<int>()(s.y) << 1)) >> 1) ^ (hash<ll>()(s.st) << 1);
        }
    };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> s[i];
    }

    ll st = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (s[i][j] == '#')
            {
                st |= 1LL << (i * W + j);
            }
        }
    }

    if (st == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    unordered_map<Status, int> memo;
    queue<Status> q;

    Status init = {0, 0, st};
    memo[init] = 0;
    q.push(init);

    int ans = INF;

    while (!q.empty())
    {
        auto [x, y, cur_st] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            ll bit = 1LL << (nx * W + ny);
            ll new_st = cur_st ^ bit;

            if (new_st == 0)
            {
                ans = min(ans, memo[{x, y, cur_st}] + 1);
                continue;
            }

            Status next = {nx, ny, new_st};
            if (memo.find(next) == memo.end())
            {
                memo[next] = memo[{x, y, cur_st}] + 1;
                q.push(next);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
