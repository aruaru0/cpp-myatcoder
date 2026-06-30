#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
    }
    os << "]";
    return os;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> y(n - 1);
    rep(i, n - 1) cin >> y[i];

    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    if (s[0] == 'S')
        dp[0][1] = -x[0];
    else
        dp[0][0] = -x[0];

    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'S')
            dp[i][1] = -x[i];
        else
            dp[i][0] = -x[i];
        dp[i][0] += max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]);
        dp[i][1] += max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << (max(dp[n - 1][0], dp[n - 1][1])) << endl;
}

int main()
{
    int t;
    cin >> t;

    rep(ti, t) solve();

    return 0;
}
