#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> l(26), r(26);
    rep(i, n)
    {
        r[s[i] - 'A']++;
    }

    ll ans = 0;
    rep(i, n)
    {
        r[s[i] - 'A']--;
        rep(j, 26)
        {
            ans += l[j] * r[j];
        }
        l[s[i] - 'A']++;
    }

    cout << ans << endl;

    return 0;
}
