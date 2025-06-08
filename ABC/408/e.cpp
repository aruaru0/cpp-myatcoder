#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        edges.emplace_back(a, b, c);
    }

    int ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        dsu uf(n);
        for (auto [a, b, c] : edges)
        {
            if (((c >> i) | (ans >> i)) != (ans >> i))
                continue;
            uf.merge(a, b);
        }
        if (!uf.same(0, n - 1))
            ans |= 1 << i;
    }
    cout << ans << endl;
    return 0;
}