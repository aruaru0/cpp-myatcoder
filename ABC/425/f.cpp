#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main()
{
    int n;
    string t;
    cin >> n >> t;
    int n2 = 1 << n;

    vector<mint> dp(n2);
    dp[n2 - 1] = 1;
    for (int s = n2 - 1; s; s--)
    {
        char pre = '-';
        rep(i, n) if (s >> i & 1)
        {
            if (pre != t[i])
                dp[s ^ 1 << i] += dp[s];
            pre = t[i];
        }
    }

    cout << dp[0].val() << endl;
    return 0;
}