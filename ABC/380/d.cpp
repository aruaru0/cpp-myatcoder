#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int f(ll l, ll r, ll k)
{
    int res = 0;
    while (l + 1 < r)
    {
        ll c = (l + r) / 2;
        if (k < c)
            r = c;
        else
            l = c, res++;
    }
    return res;
}

char flip(char c)
{
    if (islower(c))
        return c - 'a' + 'A';
    return c - 'A' + 'a';
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    rep(qi, q)
    {
        ll k;
        cin >> k;
        k--;
        int si = k % n;
        k /= n;
        int cnt = f(0, 1ll << 60, k);
        char ans = s[si];
        if (cnt % 2)
            ans = flip(ans);
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}