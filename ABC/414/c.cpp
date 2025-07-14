#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

bool isPalindrome(ll x, int a)
{
    string s;
    while (x)
    {
        s += '0' + x % a;
        x /= a;
    }
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main()
{
    int a;
    ll n;
    cin >> a >> n;

    ll ans = 0;
    auto check = [&](string s)
    {
        ll y = stoll(s);
        if (y <= n && isPalindrome(y, a))
            ans += y;
    };
    for (ll x = 1; x < 1e6; x++)
    {
        string s = to_string(x);
        string rs = s;
        reverse(rs.begin(), rs.end());

        string t = s + rs;

        check(t);

        s.pop_back();
        t = s + rs;
        check(t);
    }
    cout << ans << endl;
    return 0;
}