#include <bits/stdc++.h>
using namespace std;

#define M 5000
#define INF (int)2e+9

int main(void)
{
    int n, x, v, a, c;
    int dp[3][M + 1] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j + 1] = -INF;
        }
    }

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> a >> c;
        for (int j = x; j >= c; j--)
        {
            dp[v - 1][j] = max(dp[v - 1][j], dp[v - 1][j - c] + a);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < x; j++)
        {
            dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
        }
    }

    int idx[3] = {0, 0, 0};
    for (int i = 0; i < x; i++)
    {
        if ((dp[0][idx[0]] <= dp[1][idx[1]]) && (dp[0][idx[0]] <= dp[2][idx[2]]))
            idx[0]++;
        else if ((dp[1][idx[1]] <= dp[0][idx[0]]) && (dp[1][idx[1]] <= dp[2][idx[2]]))
            idx[1]++;
        else
            idx[2]++;
    }
    cout << min(dp[0][idx[0]], min(dp[1][idx[1]], dp[2][idx[2]])) << endl;
    return 0;
}
