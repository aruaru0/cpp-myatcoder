#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int m = 26;

    if (s == t)
        return 0;
    {
        set<char> st(t.begin(), t.end());
        if (st.size() == m)
            return -1;
    }

    set<pair<int, int>> edges;
    rep(i, n)
    {
        edges.emplace(s[i] - 'a', t[i] - 'a');
    }
    vector<int> inDeg(m), outDeg(m);
    for (auto e : edges)
    {
        outDeg[e.first]++;
        inDeg[e.second]++;
    }
    rep(i, m) if (outDeg[i] > 1) return -1;

    int ans = edges.size();
    scc_graph g(m);
    for (auto [a, b] : edges)
    {
        if (a == b)
            ans--;
        else
        {
            g.add_edge(a, b);
        }
    }
    for (auto grp : g.scc())
    {
        if (grp.size() >= 2)
        {
            bool br = false;
            for (int v : grp)
                if (inDeg[v] > 1)
                    br = true;
            if (!br)
                ans++;
        }
    }
    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}