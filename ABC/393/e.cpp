#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    const int m = 1000000;
    vector<int> num(m + 1);
    for (int na : a)
        num[na]++;
    vector<int> c(m + 1);
    for (int j = 1; j <= m; j++)
    {
        for (int i = j; i <= m; i += j)
            c[j] += num[i];
    }
    vector<int> best(m + 1);
    for (int g = 1; g <= m; g++)
    {
        if (c[g] < k)
            continue;
        for (int i = g; i <= m; i += g)
            best[i] = g;
    }

    rep(i, n)
    {
        int ans = best[a[i]];
        cout << ans << '\n';
    }
    return 0;
}