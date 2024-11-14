#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> a(n);
    rep(i, n)
    {
        a[i] = (i + 1) * (s[i] - '0');
    }
    rep(i, n - 1)
    {
        a[i + 1] += a[i];
    }

    ll carry = 0;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        carry += a[i];
        ans.push_back(carry % 10);
        carry /= 10;
    }
    while (carry > 0)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
