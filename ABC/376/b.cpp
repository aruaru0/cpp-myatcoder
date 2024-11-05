#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int f(int n, int s, int t, int x)
{
    if (s > t)
        swap(s, t);
    if (s < x && x < t)
        return n - (t - s);
    return t - s;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int l = 0, r = 1;
    int ans = 0;
    rep(qi, q)
    {
        char h;
        int t;
        cin >> h >> t;
        t--;

        if (h == 'L')
        {
            ans += f(n, l, t, r);
            l = t;
        }
        else
        {
            ans += f(n, r, t, l);
            r = t;
        }
    }

    cout << ans << endl;
    return 0;
}