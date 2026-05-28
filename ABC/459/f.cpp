#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] += n - i;

    vector<pair<ll, int>> s;
    rep(i, n)
    {
        ll b = a[i], w = 1;
        while (s.size())
        {
            auto [nb, nw] = s.back();
            if ((nb + nw - 1) / nw <= b / w)
                break;
            b += nb;
            w += nw;
            s.pop_back();
        }
        s.emplace_back(b, w);
    }

    vector<ll> d;
    for (auto [b, w] : s)
    {
        rep(i, w) d.push_back(b / w + (w - i <= b % w));
    }

    ll ans = 0, sum = 0;
    rep(i, n)
    {
        sum += a[i] - d[i];
        ans += sum;
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