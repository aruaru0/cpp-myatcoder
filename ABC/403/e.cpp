#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Trie
{
    vector<map<char, int>> to;
    Trie() : to(1) {}
    int add(const string &s)
    {
        int v = 0;
        for (char c : s)
        {
            if (to[v].count(c) == 0)
            {
                int u = to.size();
                to[v][c] = u;
                to.push_back(map<char, int>());
            }
            v = to[v][c];
        }
        return v;
    }

    int ans;
    vector<bool> ng;
    vector<int> num_y;
    void init()
    {
        ans = 0;
        int n = to.size();
        ng.resize(n);
        num_y.resize(n);
    }
    void addx(int v)
    {
        if (ng[v])
            return;
        ng[v] = true;
        ans -= num_y[v];
        for (auto [c, u] : to[v])
            addx(u);
    }
    void addy(int v)
    {
        if (ng[v])
            return;
        ans++;
        num_y[v]++;
    }
};

int main()
{
    int q;
    cin >> q;

    Trie t;
    vector<pair<int, int>> qs;
    rep(qi, q)
    {
        int type;
        string s;
        cin >> type >> s;
        int v = t.add(s);
        qs.emplace_back(type, v);
    }
    t.init();

    for (auto [type, v] : qs)
    {
        if (type == 1)
            t.addx(v);
        else
            t.addy(v);
        cout << t.ans << '\n';
    }
    return 0;
}