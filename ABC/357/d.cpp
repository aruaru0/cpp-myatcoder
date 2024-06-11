#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using mint = modint998244353;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    ll x = n;
    mint r = 1;
    while (x > 0)
    {
        x /= 10;
        r *= 10;
    }
    mint ans = mint(n) * ((1 - r.pow(n))) / (mint(1) - r);

    cout << ans.val() << endl;
}