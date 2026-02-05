#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n * 10, -1);
    queue<int> q;
    auto push = [&](int x, int d, int ps)
    {
        x %= n;
        int s = x * 10 + d;
        if (dp[s] != -1)
            return;
        dp[s] = ps;
        q.push(s);
    };
    for (int d = 1; d <= 9; d++)
        push(d, d, 0);
    while (q.size())
    {
        int s = q.front();
        q.pop();
        int x = s / 10, d = s % 10;
        if (x == 0)
        {
            string ans;
            while (d)
            {
                ans += '0' + d;
                s = dp[s];
                d = s % 10;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            return 0;
        }
        while (d < 10)
        {
            push(x * 10 + d, d, s);
            d++;
        }
    }
    cout << -1 << endl;
    return 0;
}