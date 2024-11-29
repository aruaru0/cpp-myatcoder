#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmin(int &a, int b) { a = min(a, b); }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;

    int m = 20, m2 = 1 << m;

    vector<vector<int>> is(m);
    rep(i, n) is[a[i]].push_back(i);

    const int INF = 1001001001;
    auto getNext = [&](int c, int i)
    {
        auto &nis = is[c];
        int j = lower_bound(nis.begin(), nis.end(), i) - nis.begin();
        j++;
        if (j < nis.size())
            return nis[j] + 1;
        return INF;
    };

    vector<int> dp(m2, INF);
    dp[0] = 0;

    int ans = 0;
    rep(s, m2)
    {
        int pc = __builtin_popcount(s);
        if (dp[s] != INF)
            ans = max(ans, pc);
        rep(c, m)
        {
            if (s >> c & 1)
                continue;
            chmin(dp[s | 1 << c], getNext(c, dp[s]));
        }
    }

    cout << ans * 2 << endl;
    return 0;
}