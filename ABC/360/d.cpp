#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> plus, minus;
    rep(i, n)
    {
        int x;
        cin >> x;
        if (s[i] == '1')
        {
            plus.emplace_back(x);
        }
        else
        {
            minus.emplace_back(x);
        }
    }

    sort(minus.begin(), minus.end());

    ll ans = 0;
    for (auto from : plus)
    {
        ll to = from + t * 2;
        ll diff = upper_bound(minus.begin(), minus.end(), to) - lower_bound(minus.begin(), minus.end(), from);
        ans += diff;
    }

    cout << ans << endl;
}
