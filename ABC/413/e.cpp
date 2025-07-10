#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int N;
    cin >> N;
    int n = 1 << N;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    for (int w = 1; w < n; w <<= 1)
    {
        for (int l = 0; l < n; l += w * 2)
        {
            if (p[l] > p[l + w])
            {
                rep(i, w) swap(p[l + i], p[l + i + w]);
            }
        }
    }

    rep(i, n) cout << p[i] << ' ';
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}