#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(2);
    vector<pair<char, int>> d(1, {s[0], 0});
    for (char c : s)
    {
        cnt[c - '0']++;
        if (d.back().first == c)
        {
            d.back().second++;
        }
        else
        {
            d.emplace_back(c, 1);
        }
    }

    int ans = n * 2;
    for (auto [c, num] : d)
    {
        int i = c - '0';
        vector<int> ncnt = cnt;
        ncnt[i] -= num;
        int now = ncnt[i] * 2 + ncnt[i ^ 1];
        ans = min(ans, now);
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}