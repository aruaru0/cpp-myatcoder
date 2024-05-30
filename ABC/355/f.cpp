#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, q;
    cin >> n >> q;
    int m = 10;
    vector<dsu> uf(m + 1, dsu(n));
    vector<int> num(m + 1);
    rep(qi, n - 1 + q)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        for (int i = c; i <= m; i++)
        {
            if (uf[i].same(a, b))
                continue;
            num[i]++;
            uf[i].merge(a, b);
        }
        if (qi < n - 1)
            continue;

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans += i * (num[i] - num[i - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}