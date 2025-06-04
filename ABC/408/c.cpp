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
    vector<int> a(n + 1);
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        a[l - 1]++;
        a[r]--;
    }
    rep(i, n)
    {
        a[i + 1] += a[i];
    }

    int ans = m;
    rep(i, n)
    {
        ans = min(ans, a[i]);
    }

    cout << ans << endl;
    return 0;
}
