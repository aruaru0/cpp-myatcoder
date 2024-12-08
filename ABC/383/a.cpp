#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int tot = 0;
    int cur_time = 0;

    for (int i = 0; i < n; i++)
    {
        int t, v;
        cin >> t >> v;
        int diff = t - cur_time;
        cur_time = t;
        tot = max(0, tot - diff) + v;
    }

    cout << tot << endl;
}