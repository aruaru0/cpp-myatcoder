#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n - 1) a[i + 1] = min(a[i], a[i + 1]);

    rep(j, m)
    {
        int i = lower_bound(a.begin(), a.end(), b[j], greater<int>()) - a.begin();
        if (i == n)
            cout << -1 << endl;
        else
            cout << i + 1 << endl;
    }

    return 0;
}
