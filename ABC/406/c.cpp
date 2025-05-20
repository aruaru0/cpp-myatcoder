#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dir;
    rep(i, n - 1)
    {
        dir.push_back(a[i] < a[i + 1] ? 1 : -1);
    }

    vector<P> c;
    for (auto e : dir)
    {
        if (c.size() != 0 && c.back().first == e)
        {
            c.back().second++;
        }
        else
        {
            c.push_back(P(e, 1));
        }
    }

    ll ans = 0;
    rep(i, c.size())
    {
        if (c[i].first == -1)
        {
            ll x = 0, y = 0;
            if (0 < i)
            {
                x = c[i - 1].second;
            }
            if (i < c.size() - 1)
            {
                y = c[i + 1].second;
            }
            ans += x * y;
        }
    }

    cout << ans << endl;
    return 0;
}
