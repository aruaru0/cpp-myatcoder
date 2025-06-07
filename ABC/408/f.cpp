#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int main()
{
    int n, D, R;
    cin >> n >> D >> R;
    vector<int> H(n);
    rep(i, n) cin >> H[i], H[i]--;
    vector<int> hi(n);
    rep(i, n) hi[H[i]] = i;

    vector<int> dp(n);
    segtree<int, op, e> rmq(n);
    rep(h, n)
    {
        if (h >= D)
        {
            int j = hi[h - D];
            rmq.set(j, dp[j]);
        }
        int i = hi[h];
        int l = max(0, i - R), r = min(n, i + R + 1);
        dp[i] = rmq.prod(l, r) + 1;
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
    return 0;
}