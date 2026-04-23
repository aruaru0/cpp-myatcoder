#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n + 1);
  rep(i, n) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    (a[i + 1] += m - a[i]) %= m;
  }

  for (int l = 0, r = n; l < r; l++, r--) {
    (a[l] += a[r]) %= m;
  }
  n = n / 2 + 1;
  a.resize(n);

  sort(a.begin(), a.end());
  ll l = 0, r = 0;
  rep(i, n) r += m - a[i];
  ll ans = max(l, r);
  rep(i, n) {
    l += a[i];
    r -= m - a[i];
    ans = min(ans, max(l, r));
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) solve();
  return 0;
}