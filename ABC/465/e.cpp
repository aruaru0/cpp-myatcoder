#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

int main()
{
    string N;
    cin >> N;

    using T = tuple<int, int, int>;
    map<T, mint> dp;
    dp[T(0, 0, 0)] = 1;
    for (char c : N)
    {
        c -= '0';
        map<T, mint> old;
        swap(old, dp);
        for (auto [t, x] : old)
        {
            auto [j, k, s] = t;
            rep(d, 10)
            {
                int nj = j, nk = (k * 10 + d) % 3, ns = s | 1 << d;
                if (nj == 0 && d > c)
                    continue;
                if (d < c)
                    nj = 1;
                if (s == 0 && d == 0)
                    ns = 0;
                dp[T(nj, nk, ns)] += x;
            }
        }
    }

    mint ans;
    for (auto [t, x] : dp)
    {
        auto [j, k, s] = t;
        int cnt = 0;
        if (k == 0)
            cnt++;
        if (s >> 3 & 1)
            cnt++;
        if (__builtin_popcount(s) == 3)
            cnt++;
        if (cnt == 1)
            ans += x;
    }
    ans -= 1;
    cout << ans.val() << endl;
    return 0;
}