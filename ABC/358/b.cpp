#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (cur < t)
        {
            cur = t + a;
        }
        else
        {
            cur += a;
        }

        cout << cur << endl;
    }
}