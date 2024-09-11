#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> rowSet(h);
    vector<set<int>> colSet(w);
    rep(i, h) rowSet[i].insert(-1);
    rep(i, h) rowSet[i].insert(w);
    rep(i, w) colSet[i].insert(-1);
    rep(i, w) colSet[i].insert(h);
    rep(i, h) rep(j, w)
    {
        rowSet[i].insert(j);
        colSet[j].insert(i);
    }

    auto erase = [&](int i, int j)
    {
        rowSet[i].erase(j);
        colSet[j].erase(i);
    };

    rep(qi, q)
    {
        int r, c;
        cin >> r >> c;
        --r;
        --c;

        {
            auto &st = rowSet[r];
            auto it = st.lower_bound(c);
            if (*it == c)
            {
                erase(r, c);
                continue;
            }
            else
            {
                if (*it != w)
                    erase(r, *it);
                it = st.lower_bound(c);
                it--;
                if (*it != -1)
                    erase(r, *it);
            }
        }
        {
            auto &st = colSet[c];
            auto it = st.lower_bound(r);
            if (*it != h)
                erase(*it, c);
            it = st.lower_bound(r);
            it--;
            if (*it != -1)
                erase(*it, c);
        }
    }

    int ans = 0;
    rep(i, h) ans += rowSet[i].size() - 2;
    cout << ans << endl;
    return 0;
}