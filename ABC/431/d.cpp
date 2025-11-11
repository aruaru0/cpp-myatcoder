#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define chmax(a, b) ((a) = max((a), (b)))

void chmax(ll &a, ll b)
{
    a = max(a, b);
}

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
    vector<int> w(n), h(n), b(n);

    int tot = 0;
    ll sumB = 0;
    rep(i, n)
    {
        cin >> w[i] >> h[i] >> b[i];
        tot += w[i];
        sumB += b[i];
    }

    int c = tot / 2;
    const ll inf = 1e18;
    vector<ll> dp(c + 1, -inf);
    dp[0] = 0;

    rep(i, n)
    {
        int wi = w[i];
        int diff = h[i] - b[i];
        if (diff <= 0)
        {
            continue;
        }
        for (int cur = c; cur >= wi; cur--)
        {
            chmax(dp[cur], dp[cur - wi] + diff);
        }
    }

    ll best = 0;
    for (auto e : dp)
    {
        best = max(best, e);
    }

    cout << sumB + best << endl;

    return 0;
}
