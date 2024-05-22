#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<bool> dp(1 << n);
    rep(mask, 1 << n)
        rep(i, n) for (int j = i + 1; j < n; j++)
    {
        if (((mask >> i) % 2) && ((mask >> j) % 2) && (a[i] == a[j] || b[i] == b[j]))
        {
            dp[mask] = dp[mask] || !dp[mask ^ (1 << i) ^ (1 << j)];
        }
    }

    if (dp[(1 << n) - 1])
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
    return 0;
}