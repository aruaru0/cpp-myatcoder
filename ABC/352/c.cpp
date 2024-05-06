#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using PP = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<PP> a(n);
    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
        a[i] = PP(y[i] - x[i], i);
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    rep(i, n - 1)
    {
        ans += x[a[i].second];
    }
    ans += y[a[n - 1].second];

    cout << ans << endl;
}