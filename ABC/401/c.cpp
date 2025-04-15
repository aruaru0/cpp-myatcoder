#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<mint> a(max(k, n + 1));
    vector<mint> s(a.size() + 1);

    rep(i, k) a[i] = 1;
    rep(i, k) s[i + 1] = s[i] + a[i];

    mint::set_mod(1e9);
    for (int i = k; i <= n; i++)
    {
        a[i] = s[i] - s[i - k];
        s[i + 1] = s[i] + a[i];
    }
    cout << a[n].val() << endl;
    return 0;
}