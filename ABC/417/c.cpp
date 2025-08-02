#include <iostream>
#include <vector>
#include <map>

using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> x, y;
    rep(i, n)
    {
        x[a[i] + (i + 1)]++;
        y[(i + 1) - a[i]]++;
    }

    ll ans = 0;
    for (auto [e, cnt] : x)
    {
        ans += (ll)cnt * y[e];
    }

    cout << ans << endl;
}
