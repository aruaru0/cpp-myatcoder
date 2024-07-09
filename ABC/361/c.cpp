#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1e9 + 100;
    for (int i = 0; i <= k; i++)
    {
        int v = a[n - 1 - k + i] - a[i];
        ans = min(ans, v);
    }
    cout << ans << endl;
}
