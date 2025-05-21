#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<set<int>> X(h), Y(w);
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        X[x].insert(y);
        Y[y].insert(x);
    }

    int q;
    cin >> q;
    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            x--;
            cout << X[x].size() << endl;
            for (int y : X[x])
            {
                Y[y].erase(x);
            }
            X[x].clear();
        }
        else
        {
            int y;
            cin >> y;
            y--;
            cout << Y[y].size() << endl;
            for (int x : Y[y])
            {
                X[x].erase(y);
            }
            Y[y].clear();
        }
    }

    return 0;
}
