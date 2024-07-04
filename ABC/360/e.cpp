#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<mint>> dp(k + 1, vector<mint>(2));
    dp[0][0] = 1;
    mint n2 = mint(1) / n / n;
    for (int i = 0; i < k; i++)
    {
        mint p = mint(2) * (n - 1) * n2;
        mint q = mint(2) * n2;
        dp[i + 1][0] = dp[i][0] * (1 - p) + dp[i][1] * q;
        dp[i + 1][1] = dp[i][0] * p + dp[i][1] * (1 - q);
    }

    mint ans = dp[k][0] + mint(2 + n) / 2 * dp[k][1];
    cout << ans.val() << endl;
}