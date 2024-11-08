#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    vector<int> u(N - 1), v(N - 1), deg(N, 0);
    rep(i, N - 1)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        deg[u[i]]++;
        deg[v[i]]++;
    }

    dsu uf(N);
    vector<int> c2(N);

    rep(i, N - 1)
    {
        if (deg[u[i]] == 3 && deg[v[i]] == 3)
        {
            uf.merge(u[i], v[i]);
        }
        else if (deg[u[i]] == 3 && deg[v[i]] == 2)
        {
            c2[u[i]]++;
        }
        else if (deg[u[i]] == 2 && deg[v[i]] == 3)
        {
            c2[v[i]]++;
        }
    }

    ll ans = 0;
    for (auto x : uf.groups())
    {
        ll c = 0;
        for (auto v : x)
        {
            c += c2[v];
        }
        ans += c * (c - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
