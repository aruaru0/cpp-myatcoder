#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll c2(ll n) { return n * (n - 1) / 2; }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;

    vector<vector<int>> is(n);
    rep(i, n) is[a[i]].push_back(i);

    ll ans = 0;
    rep(x, n)
    {
        ll sx = 0;
        {
            is[x].push_back(n);
            int pre = -1;
            for (int i : is[x])
            {
                sx += c2(i - pre);
                pre = i;
            }
        }
        ans += c2(n + 1) - sx;
    }

    cout << ans << endl;
    return 0;
}