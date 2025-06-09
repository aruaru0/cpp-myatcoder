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
    sort(a.begin(), a.end());

    int ans = 0;
    rep(i, n + 1)
    {
        int pos = lower_bound(a.begin(), a.end(), i) - a.begin();
        int cnt = n - pos;
        if (i <= cnt)
        {
            ans = max(ans, i);
        }
    }

    cout << ans << endl;
    return 0;
}
