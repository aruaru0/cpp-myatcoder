#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    ll n;
    string s, t;
    cin >> n >> s >> t;

    int m = s.size();
    vector<vector<int>> is(26);
    rep(i, m)
    {
        is[s[i] - 'a'].push_back(i);
    }

    auto check = [&](ll k)
    {
        ll p = 0;
        for (char c : t)
        {
            vector<int> &nis = is[c - 'a'];
            int w = nis.size();
            if (w == 0)
                return false;
            ll i = lower_bound(nis.begin(), nis.end(), p % m) - nis.begin();
            i += k - 1;
            p = (i / w) * m + nis[i % w] + p / m * m + 1;
            if (p > m * n)
                return false;
        }
        return true;
    };

    ll ok = 0, ng = m * n + 1;
    while (ok + 1 != ng)
    {
        ll wj = (ok + ng) / 2;
        if (check(wj))
            ok = wj;
        else
            ng = wj;
    }

    cout << ok << endl;
}