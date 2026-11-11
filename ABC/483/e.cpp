#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    ll d0 = 0, d1 = 0, d2 = 0;

    auto comb = [&](ll x)
    { return x * (x - 1) / 2; };
    auto calc = [&](int p = -1, int q = -1) { // p > q
        unordered_map<string, int> mp;
        rep(i, n)
        {
            string t = s[i];
            if (p != -1)
                t.erase(t.begin() + p);
            if (q != -1)
                t.erase(t.begin() + q);
            mp[t]++;
        }
        ll res = 0;
        for (auto x : mp)
            res += comb(x.second);
        return res;
    };

    d0 = calc();
    rep(i, m) d1 += calc(i);
    rep(i, m) rep(j, i) d2 += calc(i, j);

    ll c0 = d0;
    ll c1 = d1 - c0 * m;
    ll c2 = d2 - c0 * comb(m) - c1 * (m - 1);
    cout << c0 + c1 + c2 << endl;
    return 0;
}