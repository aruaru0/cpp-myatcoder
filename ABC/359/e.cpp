#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    stack<P> s;
    ll ans = 0;
    rep(i, n)
    {
        ll w = 1;
        while (!s.empty() && s.top().first <= h[i])
        {
            w += s.top().second;
            // ここまで溜まっていた矩形分の水を全部一旦捨てる
            ans -= s.top().first * s.top().second;
            s.pop();
        }
        ans += (ll)h[i] * w;
        s.push(P(h[i], w));
        cout << ans + 1 << " ";
    }
    cout << endl;
}