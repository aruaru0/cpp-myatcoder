#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto enumerate = [&](int l, int r)
    {
        vector<int> d0 = {0}, d1 = {0};
        for (int i = l; i < r; i++)
        {
            vector<int> d2 = d1;
            for (int x : d0)
                d2.push_back((x + a[i]) % m);
            swap(d0, d1);
            swap(d1, d2);
        }
        return d1;
    };

    ll ans = 0;

    int c = n / 2;
    rep(ci, 2)
    {
        auto dl = enumerate(0, c - ci);
        auto dr = enumerate(c + 1 + ci, n);
        sort(dr.begin(), dr.end());
        for (int x : dl)
        {
            if (ci)
                x += a[c], x %= m;
            int y = (m - x) % m;
            int l = lower_bound(dr.begin(), dr.end(), y) - dr.begin();
            int r = upper_bound(dr.begin(), dr.end(), y) - dr.begin();
            ans += r - l;
        }
    }

    cout << ans << endl;
    return 0;
}