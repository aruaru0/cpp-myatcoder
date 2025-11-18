#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct Rect
{
    ll lx, rx, ly, ry;
};

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<Rect> rects;
    rects.emplace_back(0, x, 0, y);

    rep(i, n)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        vector<Rect> old;
        swap(old, rects);
        for (Rect e : old)
        {
            if (c == 'X')
            {
                if (e.lx < a && a < e.rx)
                {
                    rects.emplace_back(e.lx, a, e.ly - b, e.ry - b);
                    rects.emplace_back(a, e.rx, e.ly + b, e.ry + b);
                }
                else if (e.rx <= a)
                {
                    rects.emplace_back(e.lx, e.rx, e.ly - b, e.ry - b);
                }
                else
                {
                    rects.emplace_back(e.lx, e.rx, e.ly + b, e.ry + b);
                }
            }
            else
            {
                if (e.ly < a && a < e.ry)
                {
                    rects.emplace_back(e.lx - b, e.rx - b, e.ly, a);
                    rects.emplace_back(e.lx + b, e.rx + b, a, e.ry);
                }
                else if (e.ry <= a)
                {
                    rects.emplace_back(e.lx - b, e.rx - b, e.ly, e.ry);
                }
                else
                {
                    rects.emplace_back(e.lx + b, e.rx + b, e.ly, e.ry);
                }
            }
        }
    }

    int m = rects.size();
    dsu uf(m);
    rep(i, m) rep(j, i)
    {
        Rect a = rects[i];
        Rect b = rects[j];
        ll cx = min(a.rx, b.rx) - max(a.lx, b.lx);
        ll cy = min(a.ry, b.ry) - max(a.ly, b.ly);
        if (cx < 0 || cy < 0)
            continue;
        if (cx || cy)
            uf.merge(i, j);
    }

    vector<ll> areas(m);
    rep(i, m)
    {
        Rect a = rects[i];
        areas[uf.leader(i)] += (a.rx - a.lx) * (a.ry - a.ly);
    }

    sort(areas.rbegin(), areas.rend());
    while (areas.back() == 0)
        areas.pop_back();
    reverse(areas.begin(), areas.end());
    cout << areas.size() << endl;
    for (ll a : areas)
        cout << a << ' ';
    cout << endl;
    return 0;
}