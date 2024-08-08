#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int inf = 1001001001;

int cost(int a, int b)
{
    if (a == b)
        return 0;

    if (a == 0 && b == 1)
        return -inf;
    if (a == 0 && b == 2)
        return 1;

    if (a == 1 && b == 0)
        return 1;
    if (a == 1 && b == 2)
        return -inf;

    if (a == 2 && b == 0)
        return -inf;
    if (a == 2 && b == 1)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> m = {{'R', 0}, {'P', 1}, {'S', 2}};

    vector<vector<int>> dp(n + 1, vector<int>(3, -inf));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    rep(i, n)
    {
        int y = m[s[i]];
        rep(j, 3) rep(k, 3)
        {
            if (j == k)
            {
                continue;
            }
            int score = cost(k, y);
            if (score < 0)
            {
                continue;
            }
            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + score);
        }
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}