#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<tuple<int, int, int>> es;
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        es.emplace_back(c, a, b);
    }
    sort(es.begin(), es.end());

    vector<int> A(n), B(n);
    rep(i, k)
    {
        int a;
        cin >> a;
        a--;
        A[a]++;
    }
    rep(i, k)
    {
        int b;
        cin >> b;
        b--;
        B[b]++;
    }

    dsu uf(n);
    ll ans = 0;
    for (auto [c, u, v] : es)
    {
        if (uf.same(u, v))
            continue;
        u = uf.leader(u);
        v = uf.leader(v);
        if (A[v])
            swap(u, v);
        if (A[u] && B[v])
        {
            int x = min(A[u], B[v]);
            ans += (ll)c * x;
            A[u] -= x;
            B[v] -= x;
        }
        int sumA = A[u] + A[v];
        int sumB = B[u] + B[v];
        uf.merge(u, v);
        A[uf.leader(u)] = sumA;
        B[uf.leader(u)] = sumB;
    }

    cout << ans << endl;
    return 0;
}