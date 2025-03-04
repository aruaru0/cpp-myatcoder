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

    const int inf = 1e9;
    vector<int> b(1e6 + 1, -1);

    int ans = inf;
    rep(i, n)
    {
        if (b[a[i]] != -1)
        {
            ans = min(ans, i - b[a[i]] + 1);
        }
        b[a[i]] = i;
    }

    if (ans == inf)
        ans = -1;
    cout << ans << endl;

    return 0;
}
