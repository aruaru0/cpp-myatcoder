#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    ll t = 0;
    rep(i, n)
    {
        ans += (ll)(h[i] / 5) * 3;
        int q = h[i] % 5;
        while (q > 0)
        {
            t++;
            if (t % 3 == 0)
            {
                q -= 3;
            }
            else
            {
                q--;
            }
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
