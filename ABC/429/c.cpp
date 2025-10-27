#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    rep(i, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }

    ll ans = 0;
    for (auto [e, num] : m)
    {
        if (num > 1)
        {
            ans += (ll)num * (num - 1) / 2 * (n - num);
        }
    }

    cout << ans << endl;
}