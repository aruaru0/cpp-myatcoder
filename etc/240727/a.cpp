#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint998244353;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (b > a)
            swap(a, b);
        node[a].push_back(b);
    }

    mint cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cnt *= (i + 1);
    }
    dsu d(n);

    for (int i = 0; i < n; i++)
    {
        for (auto v : node[i])
        {
            d.merge(i, v);
        }
        cnt /= d.size(i);
    }
    cout << cnt.val() << endl;
}
