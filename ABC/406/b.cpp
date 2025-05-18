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

    ll th = 1;
    rep(i, k) th *= 10;
    th--;

    ll ans = 1;
    rep(i, n)
    {
        ll a;
        cin >> a;
        if (ans > (th / a))
        {
            ans = 1;
        }
        else
        {
            ans *= a;
        }
    }

    cout << ans << endl;

    return 0;
}
