#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;

    vector<int> pre(1, -1), nxt(1, -1);
    for (int qi = 1; qi <= q; qi++)
    {
        int type, x;
        cin >> type >> x;
        if (type == 1)
        {
            pre.push_back(x);
            nxt.push_back(nxt[x]);
            if (nxt[x] != -1)
                pre[nxt[x]] = qi;
            nxt[x] = qi;
        }
        if (type == 2)
        {
            int y;
            cin >> y;
            int l = pre[x], r = nxt[x];
            ll ls = 0, rs = 0, ans = 0;
            while (l != y && r != y)
            {
                if (l != -1)
                    ls += l, l = pre[l];
                if (r != -1)
                    rs += r, r = nxt[r];
            }
            if (l == y)
                ans += ls, swap(x, y);
            else
                ans += rs;

            nxt[x] = y;
            pre[y] = x;
            cout << ans << '\n';

            pre.push_back(-1);
            nxt.push_back(-1);
        }
    }
    return 0;
}