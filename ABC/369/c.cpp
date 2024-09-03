#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> d(n - 1);
    rep(i, n - 1)
    {
        d[i] = a[i + 1] - a[i];
    }

    int cnt = 0;
    ll ans = 0;
    rep(i, n - 1)
    {
        if (i > 0 && d[i] == d[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        ans += cnt;
    }
    cout << ans + n << endl;
}