#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vector<int> d(n);
    d[0] = k;

    priority_queue<pair<ll, vector<int>>> q;
    auto push = [&](const vector<int> &d)
    {
        ll s = 0;
        rep(i, n) s += (ll)a[i] * d[i];
        // rep(i,n) cout << d[i] << ' '; cout << s << endl;
        q.emplace(s, d);
    };
    push(d);

    while (x)
    {
        auto [s, d] = q.top();
        q.pop();
        cout << s << '\n';
        int i = n - 1;
        while (d[i] == 0)
            i--;
        if (d.back() == 0)
        {
            d[i]--;
            d[i + 1]++;
            push(d);
            d[i]++;
            d[i + 1]--;
        }
        if (i >= 1 && d[i - 1] > 0)
        {
            d[i - 1]--;
            d[i]++;
            push(d);
        }
        x--;
    }
    return 0;
}