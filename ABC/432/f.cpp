#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmax(int &x, int y) { x = max(x, y); }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    {
        int sum = 0;
        rep(i, n) sum += a[i];
        if (sum % n)
        {
            cout << -1 << endl;
            return 0;
        }
        sum /= n;
        rep(i, n) a[i] -= sum;
    }

    int n2 = 1 << n;
    vector<int> sums(n2);
    rep(s, n2) rep(i, n) if (s >> i & 1) sums[s] += a[i];

    vector<int> dp(n2);
    rep(s, n2)
    {
        if (sums[s] == 0)
            dp[s]++;
        rep(i, n) if (~s >> i & 1)
        {
            chmax(dp[s | 1 << i], dp[s]);
        }
    }

    vector<int> p;
    {
        int s = n2 - 1;
        while (s)
        {
            if (sums[s] == 0)
                dp[s]--;
            rep(i, n) if (s >> i & 1)
            {
                if (dp[s] == dp[s ^ 1 << i])
                {
                    s ^= 1 << i;
                    p.push_back(i);
                    break;
                }
            }
        }
    }

    vector<tuple<int, int, int>> lefts, rights;
    {
        int sum = 0;
        rep(i, n - 1)
        {
            sum += a[p[i]];
            if (sum > 0)
                rights.emplace_back(p[i], p[i + 1], sum);
            if (sum < 0)
                lefts.emplace_back(p[i + 1], p[i], -sum);
        }
    }

    auto ans = rights;
    reverse(lefts.begin(), lefts.end());
    ans.insert(ans.end(), lefts.begin(), lefts.end());
    cout << ans.size() << endl;
    for (auto [s, t, c] : ans)
        cout << s + 1 << ' ' << t + 1 << ' ' << c << endl;
    return 0;
}