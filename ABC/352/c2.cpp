#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    long long tot = 0, diff = 0;

    rep(i, n)
    {
        long long x, y;
        cin >> x >> y;
        tot += x;
        diff = max(diff, y - x);
    }
    cout << tot + diff << endl;
}
