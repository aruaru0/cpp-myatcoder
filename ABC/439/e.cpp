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

int main()
{
    int n;
    cin >> n;

    vector<P> p(n);
    rep(i, n)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [](P a, P b)
         {
        if (a.first == b.first ) {
            return a.second > b.second;
        } 
        return a.first < b.first; });

    const int inf = 1e9 + 1;
    vector<int> dp(n, inf);
    rep(i, n)
    {
        int pos = lower_bound(dp.begin(), dp.end(), p[i].second) - dp.begin();
        dp[pos] = p[i].second;
    }
    int ans = lower_bound(dp.begin(), dp.end(), inf) - dp.begin();

    cout << ans << endl;

    return 0;
}
