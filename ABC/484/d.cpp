#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> c(n + 1);
    ll ans = 1;
    rep(i, n)
    {
        if (i && a[i] != a[i - 1])
            ans += i - c[a[i]];
        c[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}