#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    dsu uf(n);

    vector<tuple<int, int, int>> es;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (uf.same(a, b))
        {
            es.emplace_back(i, a, b);
        }
        else
        {
            uf.merge(a, b);
        }
    }

    set<int> leaders;
    rep(i, n) leaders.insert(uf.leader(i));

    cout << leaders.size() - 1 << endl;
    while (leaders.size() > 1)
    {
        auto [ei, a, b] = es.back();
        es.pop_back();
        int v = uf.leader(a);
        leaders.erase(v);
        int u = *leaders.begin();
        leaders.erase(u);
        uf.merge(u, v);
        leaders.insert(uf.leader(v));
        printf("%d %d %d\n", ei + 1, a + 1, u + 1);
    }
    return 0;
}