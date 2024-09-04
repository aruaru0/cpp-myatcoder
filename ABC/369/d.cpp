#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll inf = ll(1e18);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[0][0] = 0;
    dp[0][1] = -inf;

    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + a[i] * 2);
        dp[i + 1][1] = max(dp[i][1], dp[i][0] + a[i]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
}