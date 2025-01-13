#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> t(n), l(n);
    rep(i, n) cin >> t[i] >> l[i];

    rep(di, d)
    {
        int ans = 0;
        rep(i, n)
        {
            int w = t[i] * (l[i] + di + 1);
            ans = max(ans, w);
        }
        cout << ans << endl;
    }
}