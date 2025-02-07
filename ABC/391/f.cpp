#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using TT = tuple<ll, int, int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, K;
    cin >> n >> K;

    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    // a, b, c を大きい順にソート
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    set<T> s;
    priority_queue<TT> pq;

    auto add = [&](int i, int j, int k)
    {
        if (i < n && j < n && k < n && s.find({i, j, k}) == s.end())
        {
            s.insert({i, j, k});
            ll x = (ll)a[i] * b[j] + (ll)b[j] * c[k] + (ll)c[k] * a[i];
            pq.push({x, i, j, k});
        };
    };

    add(0, 0, 0);
    rep(t, K)
    {
        auto [val, i, j, k] = pq.top();
        pq.pop();
        if (t == K - 1)
        {
            cout << val << endl;
            return 0;
        }

        add(i + 1, j, k);
        add(i, j + 1, k);
        add(i, j, k + 1);
    }

    return 0;
}
