#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ull n, m;
    cin >> n >> m;
    ull l = 1;
    mint ans = 0;
    rep(i, 19)
    {
        ull r = min(l * 10 - 1, n);
        if (r < l)
            break;
        ll g = gcd(m, l * 10 - 1);
        ans += mint(n / (m / g)) * (r - l + 1);
        l *= 10;
    }
    cout << ans.val() << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}