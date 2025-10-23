#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct B
{
    int l, x;
    char s;
};

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    vector<B> bs;
    bs.emplace_back(n, 0, 'L');
    bs.emplace_back(0, 0, 'L');
    auto get = [&](B b, int i) -> pair<int, int>
    {
        if (b.s == 'L')
            return {b.x, b.x + w[i]};
        return {b.x - w[i], b.x};
    };

    int q;
    cin >> q;
    rep(qi, q)
    {
        int type, x;
        cin >> type >> x;
        if (type == 3)
        {
            int ac = 0, wa = bs.size();
            while (ac + 1 < wa)
            {
                int wj = (ac + wa) / 2;
                auto [l, r] = get(bs[wj], bs[wj].l);
                if (l <= x && x < r)
                    ac = wj;
                else
                    wa = wj;
            }
            int ans = n;
            if (wa < bs.size())
            {
                int bi = wa;
                ac = bs[bi].l;
                wa = bs[bi - 1].l;
                while (ac + 1 < wa)
                {
                    int wj = (ac + wa) / 2;
                    auto [l, r] = get(bs[bi], wj);
                    if (l <= x && x < r)
                        wa = wj;
                    else
                        ac = wj;
                }
                ans = n - wa;
            }
            cout << ans << '\n';
        }
        else
        {
            x--;
            if (x == 0)
                continue;
            while (1)
            {
                B b = bs.back();
                bs.pop_back();
                if (x < bs.back().l)
                {
                    bs.emplace_back(x, b.x, b.s);
                    break;
                }
            }
            {
                auto [l, r] = get(bs.back(), bs.back().l);
                if (type == 1)
                    bs.emplace_back(0, l, 'L');
                else
                    bs.emplace_back(0, r, 'R');
            }
        }
    }
    return 0;
}