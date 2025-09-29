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

    vector<vector<int>> used(h, vector<int>(w, 0));
    deque<P> q;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    auto calc = [&](int x, int y) -> int
    {
        int ret = 0;
        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (s[ny][nx] == '#')
            {
                ret++;
            }
        }
        return ret;
    };

    rep(i, h) rep(j, w)
    {
        int cnt = calc(j, i);
        if (cnt == 2 || s[i][j] == '#')
        {
            used[i][j] = 1;
        }
        if (cnt == 1 && s[i][j] == '.')
        {
            q.push_back(P(j, i));
        }
    }

    while (q.size() != 0)
    {
        for (auto [x, y] : q)
        {
            s[y][x] = '#';
        }
        deque<P> r;
        for (auto [x, y] : q)
        {
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                    continue;
                if (s[ny][nx] == '#')
                    continue;
                if (used[ny][nx])
                    continue;
                int cnt = calc(nx, ny);
                if (cnt == 1)
                {
                    r.push_back(P(nx, ny));
                }
            }
        }
        swap(q, r);
    }

    int ans = 0;
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == '#')
            ans++;
    }
    cout << ans << endl;

    return 0;
}
