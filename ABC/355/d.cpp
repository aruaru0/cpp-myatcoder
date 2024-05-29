#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        p.emplace_back(l, 0);
        p.emplace_back(r, 1);
    }
    sort(p.begin(), p.end());
    int rs = 0;
    ll ans = n * ll(n - 1) / 2;
    for (auto [x, t] : p)
    {
        if (t == 0)
            ans -= rs;
        else
            rs++;
    }
    cout << ans << endl;
    return 0;
}