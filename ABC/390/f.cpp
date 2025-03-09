#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;
    vector<vector<int>> is(n + 1);
    rep(i, n) is[a[i]].push_back(i);

    auto calc = [&](vector<int> is)
    {
        ll res = n * ll(n + 1) / 2;
        is.insert(is.begin(), -1);
        is.push_back(n);
        rep(j, is.size() - 1)
        {
            int w = is[j + 1] - is[j] - 1;
            res -= w * ll(w + 1) / 2;
        }
        return res;
    };

    ll ans = 0;
    rep(i, n)
    {
        vector<int> nis = is[i];
        nis.insert(nis.begin(), is[i + 1].begin(), is[i + 1].end());
        sort(nis.begin(), nis.end());
        ans += calc(nis) - calc(is[i + 1]);
    }
    cout << ans << endl;
    return 0;
}