#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
    int N;
    string s;
    cin >> N >> s;

    int n = 1 << N;
    vector<bool> dp(n, false);
    dp[0] = true;

    rep(i, n)
    {
        if (dp[i])
        {
            for (int j = 0; j < N; j++)
            {
                int nxt = i | (1 << j);
                if (nxt == i)
                    continue;
                if (s[nxt - 1] != '1')
                {
                    dp[nxt] = true;
                }
            }
        }
    }

    if (dp[n - 1])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        solve();
    }
    return 0;
}
