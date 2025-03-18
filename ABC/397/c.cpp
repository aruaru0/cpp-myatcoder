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

    vector<int> l(310000, 0);
    vector<int> r(310000, 0);

    int lc = 0, rc = 0;
    rep(i, n)
    {
        if (r[a[i]] == 0)
            rc++;
        r[a[i]]++;
    }

    int ans = 0;

    rep(i, n)
    {
        r[a[i]]--;
        if (r[a[i]] == 0)
            rc--;
        if (l[a[i]] == 0)
            lc++;
        l[a[i]]++;

        ans = max(ans, lc + rc);
    }

    cout << ans << endl;

    return 0;
}
