#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, l;
    cin >> n >> l;

    if (l % 3)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> d(n - 1);
    rep(i, n - 1)
    {
        cin >> d[i];
    }

    vector<vector<int>> pos(l);
    pos[0].push_back(0);
    int cur = 0;
    rep(i, n - 1)
    {
        cur += d[i];
        cur %= l;
        pos[cur].push_back(i + 1);
    }

    int step = l / 3;
    ll ans = 0;
    rep(i, step)
    {
        int x0, x1, x2;
        x0 = i;
        x1 = i + step;
        x2 = i + step * 2;
        ans += (ll)pos[x0].size() * pos[x1].size() * pos[x2].size();
    }

    cout << ans << endl;

    return 0;
}
