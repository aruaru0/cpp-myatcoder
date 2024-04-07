#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    rep(i, n)
    {
        int dist = 0, idx = 0;
        rep(j, n)
        {
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            if (dx * dx + dy * dy > dist)
            {
                dist = dx * dx + dy * dy;
                idx = j;
            }
        }
        cout << idx + 1 << endl;
    }
}