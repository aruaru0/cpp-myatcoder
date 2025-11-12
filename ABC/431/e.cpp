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

struct DIRS
{
    int d0, d1, c;

    bool operator<(const DIRS &rhs) const
    {
        return tie(d0, d1, c) < tie(rhs.d0, rhs.d1, rhs.c);
    }
};

map<DIRS, bool> dirs = {
    {{0, 2, 'A'}, true},
    {{2, 0, 'A'}, true},
    {{1, 3, 'A'}, true},
    {{3, 1, 'A'}, true},

    {{0, 3, 'B'}, true},
    {{3, 0, 'B'}, true},
    {{1, 2, 'B'}, true},
    {{2, 1, 'B'}, true},

    {{0, 1, 'C'}, true},
    {{1, 0, 'C'}, true},
    {{2, 3, 'C'}, true},
    {{3, 2, 'C'}, true},
};

struct PQ
{
    int cost;
    int i, j, c;
};

void solve()
{
    int dj[] = {1, 0, -1, 0};
    int di[] = {0, 1, 0, -1};
    int curidx[] = {2, 3, 0, 1};

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    auto compare = [](const PQ &a, const PQ &b)
    { return a.cost > b.cost; };

    auto calc = [](const int dir0, const int dir2, const char c) -> int
    {
        if (dirs[{dir0, dir2, c}] == true)
        {
            return 0;
        }
        return 1;
    };

    const int inf = 1001001001;
    vector dp(h, vector(w, vector<int>(4, inf)));
    dp[0][0][0] = 0;
    priority_queue<PQ, vector<PQ>, decltype(compare)> pq;
    pq.push({0, 0, 0, 0});
    while (pq.size() != 0)
    {
        auto cur = pq.top();
        pq.pop();
        if (dp[cur.i][cur.j][cur.c] < cur.cost)
            continue;
        rep(i, 4)
        {
            int ni = cur.i + di[i];
            int nj = cur.j + dj[i];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w)
            {
                continue;
            }
            int cost = calc(cur.c, curidx[i], s[cur.i][cur.j]);
            if (dp[ni][nj][i] > dp[cur.i][cur.j][cur.c] + cost)
            {
                dp[ni][nj][i] = dp[cur.i][cur.j][cur.c] + cost;
                pq.push({dp[ni][nj][i], ni, nj, i});
            }
        }
    }
    int ans = min(dp[h - 1][w - 1][0] + calc(0, 2, s[h - 1][w - 1]),
                  dp[h - 1][w - 1][1] + calc(1, 2, s[h - 1][w - 1]));

    std::cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}
