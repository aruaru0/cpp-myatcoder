#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<P> p(n);
    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [](P x, P y)
         { return y.first * x.second + y.second > x.first * y.second + x.second; });

    vector<ll> dp(k + 1);
    dp[0] = 1;
    rep(i, n)
    {
        vector<ll> tmp(k + 1);
        rep(j, k + 1)
        {
            tmp[j] = max(tmp[j], dp[j]);
            if (j > 0)
            {
                tmp[j] = max(tmp[j], dp[j - 1] * p[i].first + p[i].second);
            }
        }
        swap(tmp, dp);
    }

    cout << dp[k] << endl;

    return 0;
}
