#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    ll ans = 1e18;

    rep(x, 2)
    {
        int cur = x;
        vector<ll> a(n + 1);
        rep(i, n)
        {
            int v = s[i] - '0';
            if (v == cur)
            {
                a[i + 1] = a[i];
            }
            else
            {
                a[i + 1] = a[i] + c[i];
            }
            cur = 1 - cur;
        }
        vector<ll> b(n + 1);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int v = s[i] - '0';
            if (v == cur)
            {
                b[i] = b[i + 1];
            }
            else
            {
                b[i] = b[i + 1] + c[i];
            }
            cur = 1 - cur;
        }

        for (int i = 1; i < s.size(); i++)
        {
            ans = min(ans, a[i] + b[i]);
        }
    }
    cout << ans << endl;
}