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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a.push_back(a[i]);

    vector<int> s;
    s.push_back(a[0] % m);
    for (int i = 1; i < a.size(); i++)
    {
        s.push_back((s[i - 1] + a[i]) % m);
    }

    vector<int> cnt(m, 0);
    int spos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cnt[s[i]]++;
        spos++;
    }

    ll ans = 0;
    int mod = 0;
    rep(i, n)
    {
        ans += cnt[mod];
        mod = (mod + a[i]) % m;
        cnt[s[spos]]++;
        cnt[s[i]]--;
        spos++;
    }

    cout << ans << endl;
}
