#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<vector<int>> z(n);
    rep(i, n) z[i] = z_algorithm(s[i]);

    auto comp = [&](int i, int j)
    {
        int w = s[i].size();
        if (s[i] != s[j].substr(0, w))
            return (s[i] < s[j]) ? -1 : 1;
        int r = s[j].size() - w;
        if (r > 0 && z[j][w] < r)
        {
            int k = z[j][w];
            return (s[j][k] < s[j][w + k]) ? -1 : 1;
        }
        if (s[j].substr(r) != s[i])
            return (s[j].substr(r) < s[i]) ? -1 : 1;
        return 0;
    };

    vector<int> p(n);
    rep(i, n) p[i] = i;
    sort(p.begin(), p.end(), [&](int i, int j)
         {
    if (s[i].size() > s[j].size()) return comp(j,i) == 1;
    return comp(i,j) == -1; });
    {
        auto old = s;
        rep(i, n) s[i] = old[p[i]];
    }

    auto cat = [&]()
    {
        string res;
        for (string &t : s)
            res += t;
        return res;
    };

    rep(i, n - 1)
    {
        if (s[i] + s[i + 1] == s[i + 1] + s[i])
        {
            cout << cat() << '\n';
            return;
        }
    }

    swap(s[n - 2], s[n - 1]);
    string ans = cat();
    swap(s[n - 2], s[n - 1]);
    if (n >= 3)
    {
        swap(s[n - 2], s[n - 3]);
        ans = min(ans, cat());
    }
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}