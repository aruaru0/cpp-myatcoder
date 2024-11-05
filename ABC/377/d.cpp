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

    vector<int> L(m + 1, -1);
    rep(i, n)
    {
        int l, r;
        cin >> l >> r;
        L[r] = max(L[r], l);
    }

    ll ans = 0;
    int l = 1;
    rep(r, m + 1)
    {
        while (l <= L[r])
        {
            l++;
        }
        ans += r - l + 1;
    }

    cout << ans << endl;

    return 0;
}
