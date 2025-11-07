#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> ll(n), lr(n);
    vector<int> rl(n), rr(n);
    rep(i, n - 1) if (s[i] == 'L') ll[i + 1] = ll[i] + 1;
    rep(i, n - 1) if (s[i] == 'R') lr[i + 1] = lr[i] + 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == 'L')
            rl[i] = rl[i + 1] + 1;
        else
            rr[i] = rr[i + 1] + 1;
    }
    vector<int> d(n + 1);
    rep(i, n)
    {
        int s = lr[i] + rl[i], t = ll[i] + rr[i];
        d[s]++;
        d[n - t]--;
    }
    rep(i, n) d[i + 1] += d[i];
    rep(i, n) cout << d[i] << ' ';
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}