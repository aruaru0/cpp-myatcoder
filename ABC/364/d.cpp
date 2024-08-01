#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int n, q;
vector<int> a;
const int inf = int(1e9);

void solve()
{
    int b, k;
    cin >> b >> k;

    ll l = -inf, r = inf;
    while (r - l > 1)
    {
        ll m = (l + r) / 2;
        auto posl = lower_bound(a.begin(), a.end(), b - m);
        auto posr = upper_bound(a.begin(), a.end(), b + m);
        if (*posl < b - m)
        {
            posl++;
        }
        if (*posr > b + m)
        {
            posr--;
        }
        if (posr - posl + 1 >= k)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << endl;
}

int main()
{
    int n, q;
    cin >> n >> q;

    rep(i, n)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(inf);
    a.push_back(-inf);

    sort(a.begin(), a.end());

    rep(i, q)
    {
        solve();
    }
}