#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    vector<vector<int>> a(n);

    rep(i, m)
    {
        int k;
        cin >> k;
        t[i] = k;
        rep(j, k)
        {
            int x;
            cin >> x;
            x--;
            a[x].push_back(i);
        }
    }

    int ans = 0;
    rep(i, m)
    {
        if (t[i] == 0)
            ans++;
    }

    rep(i, n)
    {
        int b;
        cin >> b;
        b--;
        for (auto e : a[b])
        {
            t[e]--;
            if (t[e] == 0)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
