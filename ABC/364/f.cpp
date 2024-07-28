#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    set<int> cut;
    rep(i, n - 1) cut.insert(i);

    ll ans = 0;
    vector<tuple<int, int, int>> qs;
    rep(qi, q)
    {
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        qs.emplace_back(c, l, r);
    }
    sort(qs.begin(), qs.end());

    for (auto [c, l, r] : qs)
    {
        ans += c;
        auto it = cut.lower_bound(l);
        while (it != cut.end() && *it < r)
        {
            cut.erase(it++);
            ans += c;
        }
    }

    if (cut.size() == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}