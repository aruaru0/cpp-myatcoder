#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n);
    vector<vector<int>> groups(l);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        groups[i % l].push_back(a[i]);
    }

    vector<long long> dp(m, INF);
    dp[0] = 0;

    for (int k = 0; k < l; ++k)
    {
        if (groups[k].empty())
        {
            continue;
        }

        vector<long long> cost_k(m);
        vector<int> counts(m, 0);
        for (int val : groups[k])
        {
            counts[val]++;
        }

        long long c0 = 0;
        for (int val : groups[k])
        {
            c0 += (-val + m) % m;
        }
        cost_k[0] = c0;

        for (int v = 1; v < m; ++v)
        {
            cost_k[v] = cost_k[v - 1] + groups[k].size() - (long long)m * counts[v];
        }

        vector<long long> new_dp(m, INF);
        for (int prev_rem = 0; prev_rem < m; ++prev_rem)
        {
            if (dp[prev_rem] == INF)
            {
                continue;
            }
            for (int val_c = 0; val_c < m; ++val_c)
            {
                int rem = (prev_rem + val_c) % m;
                long long current_cost = dp[prev_rem] + cost_k[val_c];
                if (current_cost < new_dp[rem])
                {
                    new_dp[rem] = current_cost;
                }
            }
        }
        dp = new_dp;
    }

    cout << dp[0] << endl;

    return 0;
}