#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll tot = 0;
    int idx = 0;
    rep(i, m)
    {
        while (idx < n && a[idx] < b[i])
            idx++;
        if (idx == n)
        {
            cout << -1 << endl;
            return 0;
        }
        tot += a[idx];
        idx++;
    }

    cout << tot << endl;
}