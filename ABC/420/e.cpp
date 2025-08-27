#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
    int n, q;
    cin >> n >> q;

    dsu uf(n);
    vector<int> cnt(n);
    vector<bool> isBlk(n);

    rep(qi, q)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (!uf.same(u, v))
            {
                int ru = uf.leader(u);
                int rv = uf.leader(v);
                uf.merge(u, v);
                int r = uf.leader(u);
                if (r == ru)
                {
                    cnt[r] += cnt[rv];
                }
                else
                {
                    cnt[r] += cnt[ru];
                }
            }
            break;
        }
        case 2:
        {
            int u;
            cin >> u;
            u--;
            if (isBlk[u])
            {
                cnt[uf.leader(u)]--;
                isBlk[u] = false;
            }
            else
            {
                cnt[uf.leader(u)]++;
                isBlk[u] = true;
            }
            break;
        }
        case 3:
        {
            int u;
            cin >> u;
            u--;
            if (cnt[uf.leader(u)] != 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        }
        }
    }

    return 0;
}
