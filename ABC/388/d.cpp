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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> c(n), d(n + 1);
    rep(i, n)
    {
        if (i != 0)
        {
            c[i] = c[i - 1] + d[i];
            a[i] += c[i];
        }
        int cnt = min(n - i - 1, a[i]);
        a[i] -= cnt;
        d[i + 1]++;
        d[min(n, i + cnt + 1)]--;
    }

    rep(i, n) cout << a[i] << " \n"[i == n - 1];

    return 0;
}
