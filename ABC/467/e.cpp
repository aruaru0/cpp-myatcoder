#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];

    auto f = [&](int x)
    {
        return (x % m + m) % m;
    };

    vector<int> p, q, xs;
    {
        int c = 0;
        rep(i, n)
        {
            if (i % 2 == 0)
                p.push_back(f(a[i] - c));
            else
                q.push_back(f(c - a[i]));
            if (i != n - 1)
                c = f(b[i] - c);
        }
        xs = p;
        xs.insert(xs.end(), q.begin(), q.end());
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        if (xs[0] == 0)
            xs.erase(xs.begin());
    }
    // for (int c : p) cerr << c << ' '; cerr << endl;
    // for (int c : q) cerr << c << ' '; cerr << endl;

    ll now = 0;
    map<int, int> pc, qc;
    for (int c : p)
        now += f(-c), pc[c]++;
    for (int c : q)
        now += f(c), qc[c]++;
    // cerr << now << endl;
    ll ans = now;

    int px = 0;
    for (int x : xs)
    {
        now += m * ll(qc[px]);
        now += ((ll)p.size() - (ll)q.size()) * (x - px);
        px = x;
        now -= m * ll(pc[x]);
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}