#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    ll cnt_a = 0, tot_a = 0;
    rep(i, n)
    {
        tot_a += a[i];
        cnt_a++;
        if (tot_a > x)
        {
            break;
        }
    }

    ll cnt_b = 0, tot_b = 0;
    rep(i, n)
    {
        tot_b += b[i];
        cnt_b++;
        if (tot_b > y)
        {
            break;
        }
    }

    cout << min(cnt_a, cnt_b) << endl;
}