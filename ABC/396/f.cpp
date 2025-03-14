#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    rep(i, n)
    {
        int a;
        cin >> a;
        p.emplace_back(a, i);
    }
    sort(p.begin(), p.end());

    ll now = 0;
    fenwick_tree<int> t(n);
    rep(i, n)
    {
        int j = p[i].second;
        now += t.sum(j, n);
        t.add(j, 1);
    }

    for (int x = m - 1; x >= 0; x--)
    {
        cout << now << '\n';
        while (p.size() && p.back().first == x)
        {
            int j = p.back().second;
            p.pop_back();
            now += j;
            now -= n - 1 - j;
        }
    }
    return 0;
}