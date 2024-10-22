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
    vector<int> b(n - 1);
    rep(i, n - 1) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    const int inf = int(1e9 + 1);
    int l = 0, r = inf;

    while (l + 1 != r)
    {
        int m = (l + r) / 2;

        auto c = b;
        c.push_back(m);
        sort(c.begin(), c.end());
        bool ok = true;
        rep(i, n)
        {
            if (a[i] > c[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    if (r == inf)
    {
        r = -1;
    }
    cout << r << endl;

    return 0;
}
