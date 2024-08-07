#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll tot = 0;
    rep(i, n)
    {
        cin >> a[i];
        tot += a[i];
    }
    if (tot <= m)
    {
        cout << "infinite" << endl;
        return 0;
    }

    ll l = -1, r = m + 1;
    while (l + 1 != r)
    {
        ll x = (l + r) / 2;
        tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += min(x, (ll)a[i]);
        }
        if (tot > m)
        {
            r = x;
        }
        else
        {
            l = x;
        }
    }
    cout << l << endl;
}