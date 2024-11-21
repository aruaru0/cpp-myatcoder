#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> cnt(n + 2, 1);

    dsu uf(n + 2);
    vector<int> l(n + 2), r(n + 2), col(n + 2);
    rep(i, n + 2) l[i] = r[i] = col[i] = i;

    rep(qi, q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, c;
            cin >> x >> c;
            x = uf.leader(x);
            int sz = uf.size(x);

            cnt[col[x]] -= sz;
            col[x] = c;
            cnt[col[x]] += sz;

            {
                int li = uf.leader(l[x] - 1);
                if (col[li] == c)
                {
                    int nl = l[li], nr = r[x];
                    uf.merge(li, x);
                    x = uf.leader(x);
                    l[x] = nl;
                    r[x] = nr;
                    col[x] = c;
                }
            }
            {
                int ri = uf.leader(R[x] + 1);
                if (col[ri] == c)
                {
                    int nl = l[x], nr = r[ri];
                    uf.merge(ri, x);
                    x = uf.leader(x);
                    l[x] = nl;
                    r[x] = nr;
                    col[x] = c;
                }
            }
        }
        else
        {
            int c;
            cin >> c;
            cout << cnt[c] << '\n';
        }
    }
    return 0;
}