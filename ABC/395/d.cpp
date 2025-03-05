#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> p(n), pos2idx(n), idx2pos(n);
    rep(i, n)
    {
        p[i] = i;
        pos2idx[i] = i;
        idx2pos[i] = i;
    }

    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            p[a] = pos2idx[b];
        }
        if (t == 2)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int ia = pos2idx[a];
            int ib = pos2idx[b];
            pos2idx[a] = ib;
            pos2idx[b] = ia;
            idx2pos[ib] = a;
            idx2pos[ia] = b;
        }
        if (t == 3)
        {
            int a;
            cin >> a;
            a--;
            cout << idx2pos[p[a]] + 1 << endl;
        }
    }
    return 0;
}
