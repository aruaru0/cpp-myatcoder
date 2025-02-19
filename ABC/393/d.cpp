#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> p;
    rep(i, n) if (s[i] == '1') p.push_back(i);
    int k = p.size();
    rep(i, k) p[i] -= i;
    int med = p[k / 2];
    ll ans = 0;
    rep(i, k) ans += abs(med - p[i]);
    cout << ans << endl;
    return 0;
}