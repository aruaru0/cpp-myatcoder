#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll n;
    cin >> n;

    ll ans = (long long)sqrtl(n / 2) + (long long)sqrtl(n / 4);
    cout << ans << endl;
    return 0;
}
