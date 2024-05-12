#include <iostream>
#include <vector>

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

    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > k)
        {
            ans++;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    if (sum != 0)
    {
        ans++;
    }
    cout << ans << endl;
}