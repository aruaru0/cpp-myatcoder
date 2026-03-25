#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    string x, y;
    int q;
    cin >> x >> y >> q;
    x = y + x;

    vector<string> S = {y, x};

    vector<ll> len = {y.size(), x.size()};
    vector cnt(2, vector<ll>(26));
    rep(i, 2)
    {
        for (char c : S[i])
            cnt[i][c - 'a']++;
    }
    vector csum(26, vector<ll>(x.size() + 1));
    rep(i, x.size()) csum[x[i] - 'a'][i + 1]++;
    rep(i, 26) rep(j, x.size()) csum[i][j + 1] += csum[i][j];

    while (len.back() < 1e18)
    {
        int i = len.size() - 1, j = i - 1;
        len.push_back(len[i] + len[j]);
        cnt.push_back(cnt[i]);
        rep(c, 26) cnt.back()[c] += cnt[j][c];
    }

    auto f = [&](auto f, int i, ll r, char c) -> ll
    {
        if (i <= 1)
            return csum[c][r];
        if (len[i - 1] < r)
            return cnt[i - 1][c] + f(f, i - 2, r - len[i - 1], c);
        else
            return f(f, i - 1, r, c);
    };

    rep(qi, q)
    {
        ll l, r;
        char c;
        cin >> l >> r >> c;
        --l;
        c -= 'a';
        ll ans = f(f, len.size(), r, c) - f(f, len.size(), l, c);
        cout << ans << endl;
    }
    return 0;
}