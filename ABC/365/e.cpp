#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> s(n + 1);
    ll tot = 0;

    for (int i = 0; i < n; i++)
    {
        s[i + 1] = s[i] ^ a[i];
        tot += (ll)a[i];
    }

    ll ans = 0;
    for (int k = 0; k < 30; k++)
    {
        ll one = 0;
        ll zero = 0;
        for (int i = 0; i <= n; i++)
        {
            if ((s[i] >> k) % 2 == 1)
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        ans += (one * zero) << k;
    }

    cout << ans - tot << endl;
}