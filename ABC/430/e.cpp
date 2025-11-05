#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    vector<int> z = z_algorithm(b + "$" + a + a);
    rep(i, n)
    {
        if (z[n + 1 + i] == n)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}