#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        if (m >= h)
        {
            ans++;
        }
        m = max(0, m - h);
    }

    cout << ans << endl;
}