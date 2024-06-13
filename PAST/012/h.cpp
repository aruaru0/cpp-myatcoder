#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, x;
    cin >> n >> x;

    vector<P> dp(x + 1, {0, 0});

    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<P> tmp(x + 1, {0, 0});
        copy(dp.begin(), dp.end(), tmp.begin());
        for (int j = x; j >= 0; j--)
        {
            if (j - b < 0)
                continue;
            if (tmp[j].first < dp[j - b].first + c)
            {
                tmp[j] = {dp[j - b].first + c, dp[j - b].second + a};
            }
            else if (tmp[j].first == dp[j - b].first + c &&
                     tmp[j].second > dp[j - b].second + a)
            {
                tmp[j] = {dp[j - b].first + c, dp[j - b].second + a};
            }
        }

        dp = tmp;

        // rep(j, x + 1)
        // {
        //     cout << dp[j].first << ":" << dp[j].second << " ";
        // }
        // cout << endl;
    }

    int g = 0, s = 0, b = 0;
    rep(i, x + 1)
    {
        if (dp[i].first > g)
        {
            g = dp[i].first;
            s = dp[i].second;
            b = x - i;
        }
        else if (dp[i].first == g && dp[i].second < s)
        {
            g = dp[i].first;
            s = dp[i].second;
            b = x - i;
        }
    }

    cout << g << " " << (int)1e9 - s << " " << b << endl;
}