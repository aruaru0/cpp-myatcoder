#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    ll ans = 0;
    rep(i, n)
    {
        sum -= a[i];
        ans += sum * a[i];
    }

    cout << ans << endl;
    return 0;
}