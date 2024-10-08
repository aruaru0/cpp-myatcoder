#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> k(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        ans += k[i];
    }

    for (int bit = 0; bit < 1 << n; bit++)
    {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                a += k[i];
            }
            else
            {
                b += k[i];
            }
        }
        ans = min(ans, max(a, b));
    }

    cout << ans << endl;
}