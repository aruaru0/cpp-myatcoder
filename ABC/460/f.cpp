#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Lowest Common Ancestor by binary lifting
// https://youtu.be/8uowVvQ_-Mo?t=4306
template <typename T = int> // T: type of cost
struct lca
{
    int n, root, l;
    vector<vector<int>> to;
    vector<vector<T>> co;
    vector<int> dep;
    vector<T> costs;
    vector<vector<int>> par;
    lca() {}
    lca(int n) : n(n), to(n), co(n), dep(n), costs(n)
    {
        l = 0;
        while ((1 << l) < n)
            ++l;
        par = vector<vector<int>>(n + 1, vector<int>(l, n));
    }
    void addEdge(int a, int b, T c = 0)
    {
        to[a].push_back(b);
        co[a].push_back(c);
        to[b].push_back(a);
        co[b].push_back(c);
    }
    void dfs(int v, int d = 0, T c = 0, int p = -1)
    {
        if (p != -1)
            par[v][0] = p;
        dep[v] = d;
        costs[v] = c;
        for (int i = 0; i < to[v].size(); ++i)
        {
            int u = to[v][i];
            if (u == p)
                continue;
            dfs(u, d + 1, c + co[v][i], v);
        }
    }

    void init(int _root = 0)
    {
        root = _root;
        dfs(root);
        for (int i = 0; i < l - 1; ++i)
        {
            for (int v = 0; v < n; ++v)
            {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }
    // LCA
    int up(int v, int k)
    {
        for (int i = l - 1; i >= 0; --i)
        {
            int len = 1 << i;
            if (k >= len)
                k -= len, v = par[v][i];
        }
        return v;
    }
    int operator()(int a, int b)
    {
        if (dep[a] > dep[b])
            swap(a, b);
        b = up(b, dep[b] - dep[a]);
        if (a == b)
            return a;
        for (int i = l - 1; i >= 0; --i)
        {
            int na = par[a][i], nb = par[b][i];
            if (na != nb)
                a = na, b = nb;
        }
        return par[a][0];
    }
    int length(int a, int b)
    {
        int c = (*this)(a, b);
        return dep[a] + dep[b] - dep[c] * 2;
    }
    T dist(int a, int b)
    {
        int c = (*this)(a, b);
        return costs[a] + costs[b] - costs[c] * 2;
    }
};
lca<int> g;

struct S
{
    int a, b;
};
bool chmax(int &a, int b)
{
    if (a >= b)
        return false;
    a = b;
    return true;
}
S op(S s, S t)
{
    if (s.a == -1)
        return t;
    if (t.a == -1)
        return s;
    int a = s.a, b = s.b, d = g.dist(s.a, s.b);
    if (chmax(d, g.dist(b, t.a)))
        a = t.a;
    if (chmax(d, g.dist(b, t.b)))
        a = t.b;
    if (chmax(d, g.dist(a, s.a)))
        b = s.a;
    if (chmax(d, g.dist(a, t.a)))
        b = t.a;
    if (chmax(d, g.dist(a, t.b)))
        b = t.b;
    return S(a, b);
}
S e() { return S(-1, -1); }

int main()
{
    int n;
    cin >> n;
    g = lca<int>(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.addEdge(a, b, 1);
    }
    g.init();

    segtree<S, op, e> t(n);
    rep(i, n) t.set(i, S(i, i));
    vector<bool> on(n, true);

    int q;
    cin >> q;
    rep(qi, q)
    {
        int v;
        cin >> v;
        --v;
        on[v] = !on[v];
        if (on[v])
            t.set(v, S(v, v));
        else
            t.set(v, S(-1, -1));
        auto [a, b] = t.all_prod();
        cout << g.dist(a, b) << '\n';
    }
    return 0;
}