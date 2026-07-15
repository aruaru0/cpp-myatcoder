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

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    int kn = 2 * k + 1;
    vector<ll> dp(kn, 0);

    rep(i, n)
    {
        vector<ll> tmp(kn, 0);
        rep(j, kn)
        {
            if (j % 2 == 0)
            {
                chmax(tmp[j], dp[j] + a[i]);
            }
            else
            {
                chmax(tmp[j], dp[j] + b[i]);
            }
        }
        rep(j, k * 2)
        {
            if ((j + 1) % 2 == 0)
            {
                chmax(tmp[j + 1], dp[j] + a[i]);
            }
            else
            {
                chmax(tmp[j + 1], dp[j] + b[i]);
            }
        }
        swap(tmp, dp);
    }

    ll ans = dp[0];
    rep(i, kn)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
