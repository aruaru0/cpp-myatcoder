#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    sort(l.begin(), l.end(), greater<int>());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << l[i] << endl;
    // }
    int ans = max(0, t - l[p - 1]);
    cout << ans << endl;
}