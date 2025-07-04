#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main()
{
    int N, C;
    cin >> N >> C;
    vector<int> a(N);
    long long sum = 0;
    int max_a = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += a[i];
        max_a = max(max_a, a[i]);
    }

    map<int, int> cnt;
    for (int x : a)
    {
        cnt[x]++;
    }

    int max_v = max_a + N + 1;
    vector<mint> dp(max_v + 1, 0);

    mint sa = 0, sd = 0;

    for (int k = max_v - 1; k > 0; k--)
    {
        mint num = sum + sd;
        mint den = (mint)k + sa;

        if (den.val() == 0)
        {
            continue;
        }

        dp[k] = num / den;

        if (cnt.count(k + 1))
        {
            int v = cnt[k + 1];
            sa += (mint)v * (k + 1);
            sd += (mint)v * (k + 1) * dp[k];
        }
    }

    cout << dp[a[C - 1]].val() << endl;

    return 0;
}
