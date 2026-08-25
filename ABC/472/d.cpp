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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<int> cnt_h(h), cnt_w(w);
    rep(r, h) rep(c, w)
    {
        if (s[r][c] == '#')
        {
            cnt_h[r]++;
            cnt_w[c]++;
        }
    }

    const ll inf = 1e18;
    vector<vector<ll>> dist(h, vector<ll>(w, inf));
    deque<P> q;

    rep(r, h) rep(c, w)
    {
        if (cnt_h[r] == 0 && cnt_w[c] == 0)
        {
            q.push_back({r, c});
            dist[r][c] = 0;
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (q.size() != 0)
    {
        auto [cur_r, cur_c] = q[0];
        q.pop_front();
        rep(i, 4)
        {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
            {
                continue;
            }
            if (s[nr][nc] == '#')
                continue;

            if (dist[nr][nc] == inf)
            {
                q.push_back({nr, nc});
                dist[nr][nc] = dist[cur_r][cur_c] + 1;
            }
        }
    }

    ll ans = 0;
    rep(r, h) rep(c, w)
    {
        if (dist[r][c] <= k)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
