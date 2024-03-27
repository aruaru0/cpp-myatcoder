#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main()
{
    ll h, w, m;
    cin >> h >> w >> m;

    vector<ll> T(m), A(m), X(m);
    rep(i, m)
    {
        cin >> T[i] >> A[i] >> X[i];
    }

    set<ll> used_h, used_w;
    vector<ll> cnt(210000, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        int t = T[i];
        int a = A[i];
        int x = X[i];
        a--;
        if (t == 1)
        {
            if (used_h.find(a) == used_h.end())
            {
                cnt[x] += w - used_w.size();
                used_h.insert(a);
            }
        }
        else
        {
            if (used_w.find(a) == used_w.end())
            {
                cnt[x] += h - used_h.size();
                used_w.insert(a);
            }
        }
    }

    ll tot = h * w;
    rep(i, 210000)
    {
        tot -= cnt[i];
    }

    cnt[0] += tot;

    vector<pair<ll, ll>> ans;
    rep(i, 210000)
    {
        if (cnt[i] != 0)
        {
            ans.emplace_back(i, cnt[i]);
        }
    }

    cout << ans.size() << endl;
    for (auto [c, x] : ans)
    {
        cout << c << " " << x << endl;
    }
}