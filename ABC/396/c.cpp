#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    rep(i, n) cin >> b[i];
    vector<int> w(m);
    rep(i, m) cin >> w[i];

    // b, wを大きい順に並べる
    sort(b.begin(), b.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());

    vector<ll> bsum(n + 1, 0);
    vector<ll> wsum(m + 1, 0);
    ll max_pos = 0;
    rep(i, n) bsum[i + 1] = bsum[i] + b[i];
    for (int i = n - 1; i >= 0; i--)
    {
        bsum[i] = max(bsum[i], bsum[i + 1]);
    }

    rep(i, m) wsum[i + 1] = wsum[i] + w[i];

    // bsum[i]を表示
    ll ans = 0;
    for (int i = 0; i <= min(n, m); i++)
        ans = max(ans, bsum[i] + wsum[i]);

    cout << ans << endl;
    return 0;
}
