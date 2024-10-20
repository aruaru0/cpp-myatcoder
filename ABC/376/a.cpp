#include <iostream>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    int cnt = 0;
    int cur = -10000;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t - cur < c)
        {
            continue;
        }
        cur = t;
        cnt++;
    }
    cout << cnt << endl;
}