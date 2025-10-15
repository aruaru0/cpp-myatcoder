#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int si = 0, sj = 0;
    rep(i, h) rep(j, w) if (s[i][j] == 'T') si = i, sj = j;

    using S = tuple<int, int, int, int, int, int>;
    map<S, int> dist;
    queue<S> q;

    auto push = [&](int li, int ri, int lj, int rj, int ti, int tj, int d)
    {
        li = max(li, ti - si);
        ri = min(ri, h + (ti - si));
        lj = max(lj, tj - sj);
        rj = min(rj, w + (tj - sj));
        if (li <= ti && ti < ri && lj <= tj && tj < rj)
        {
            if (s[ti][tj] == '#')
                return;
        }
        S st(li, ri, lj, rj, ti, tj);
        if (dist.count(st))
            return;
        dist[st] = d;
        q.emplace(st);
    };

    push(0, h, 0, w, si, sj, 0);
    while (q.size())
    {
        int d = dist[q.front()];
        auto [li, ri, lj, rj, ti, tj] = q.front();
        q.pop();

        {
            int cnt = 0;
            for (int i = li; i < ri; i++)
            {
                for (int j = lj; j < rj; j++)
                {
                    if (s[i][j] == '#')
                        cnt++;
                }
            }
            if (cnt == 0)
            {
                cout << d << endl;
                return 0;
            }
        }

        push(li, ri, lj, rj, ti - 1, tj, d + 1);
        push(li, ri, lj, rj, ti + 1, tj, d + 1);
        push(li, ri, lj, rj, ti, tj - 1, d + 1);
        push(li, ri, lj, rj, ti, tj + 1, d + 1);
    }

    cout << -1 << endl;
    return 0;
}