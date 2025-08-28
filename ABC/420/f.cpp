#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

template <class T = long long>
struct CartesianTree
{
    int n, root;
    vector<int> l, r;
    CartesianTree() {}
    CartesianTree(const vector<T> &a, bool _max = true)
    {
        n = a.size();
        l = r = vector<int>(n, -1);
        vector<int> st;
        rep(i, n)
        {
            int p = -1;
            while (st.size() && !((a[st.back()] < a[i]) ^ _max))
            {
                int j = st.back();
                st.pop_back();
                r[j] = p;
                p = j;
            }
            l[i] = p;
            st.push_back(i);
        }
        rep(i, st.size() - 1) r[st[i]] = st[i + 1];
        root = st[0];
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    ll ans = 0;
    vector f(n + 1, vector<ll>(m + 2));
    auto tri = [&](ll s) -> ll
    {
        if (s < 0)
            return 0;
        return (s + 2) * (s + 1) / 2;
    };
    for (int h = 1; h <= n; h++)
        rep(c, m + 2)
        {
            f[h][c] = f[h - 1][c] + tri(k / h - 1 - c);
        }

    auto add = [&](int l, int r, int h)
    {
        l++;
        r++;
        ans += f[h][0];
        ans -= f[h][l];
        ans -= f[h][r];
        ans += f[h][l + r];
    };

    vector<int> a(m);
    rep(bi, n)
    {
        rep(i, m)
        {
            a[i]++;
            if (s[bi][i] == '#')
                a[i] = 0;
        }
        CartesianTree t(a, false);
        auto dfs = [&](auto dfs, int l, int r, int v) -> void
        {
            if (v == -1)
                return;
            add(v - l, r - v, a[v]);
            dfs(dfs, l, v - 1, t.l[v]);
            dfs(dfs, v + 1, r, t.r[v]);
        };
        dfs(dfs, 0, m - 1, t.root);
    }

    cout << ans << endl;
    return 0;
}