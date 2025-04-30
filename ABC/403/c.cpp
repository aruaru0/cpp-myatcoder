#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<set<int>> g(n);

    rep(qi, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            g[x].insert(y);
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            x--;
            g[x].insert(0);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            if (g[x].find(0) != g[x].end() || g[x].find(y) != g[x].end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
