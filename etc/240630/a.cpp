#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> f;

    f.emplace_back(1);
    f.emplace_back(1);
    while (f.back() <= n)
    {
        ll x = f.back() + f[f.size() - 2];
        f.emplace_back(x);
    }

    // for (int i = 0; i < f.size(); i++)
    //     cout << f[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i = f.size() - 1; i >= 0; i--)
    {
        while (n >= f[i])
        {
            // cout << n << endl;
            n -= f[i];
            ans++;
        }
    }
    cout << ans << endl;
}