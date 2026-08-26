#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> col(n, -1);
    vector<int> vs;
    auto f = [&](auto f, int v, int c) -> bool
    {
        if (col[v] != -1)
        {
            if (col[v] != c)
            {
                reverse(vs.begin(), vs.end());
                while (vs.back() != v)
                    vs.pop_back();
                return true;
            }
            return false;
        }
        vs.push_back(v);
        col[v] = c;
        for (int u : to[v])
        {
            if (f(f, u, !c))
                return true;
        }
        vs.pop_back();
        return false;
    };
    f(f, 0, 0);
    if (vs.size())
    {
        cout << vs.size() << '\n';
        for (int v : vs)
            cout << v + 1 << ' ';
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}