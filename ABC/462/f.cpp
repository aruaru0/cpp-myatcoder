#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void chmin(int &a, int b) { a = min(a, b); }

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    const int INF = 1001001001;
    deque emp(k + 2, vector<int>(3, INF));
    auto dp = emp;
    dp[0][0] = 0;
    rep(i, n)
    {
        auto old = emp;
        swap(old, dp);
        rep(j, k + 2) rep(a, 3)
        {
            for (char c : "ABC?")
            {
                int now = old[j][a];
                if (c != '?')
                    now++;
                if (c == '?')
                    c = s[i];
                int nj = j, na = a;
                if ("ABC"[a] == c)
                    na++;
                else if (c == 'A')
                    na = 1;
                else
                    na = 0;
                if (na == 3)
                    na = 0, nj++;
                if (nj > k + 1)
                    continue;
                chmin(dp[nj][na], now);
            }
        }
        if (i >= 2 && s.substr(i - 2, 3) == "ABC")
        {
            dp.pop_front();
            dp.push_back(emp[0]);
        }
    }

    int ans = *min_element(dp[k].begin(), dp[k].end());
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}