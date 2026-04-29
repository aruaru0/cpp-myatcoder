#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;

  auto f = [&](vector<ll> co) {
    ll res = 0, x = 0;
    map<ll, int> d;
    rep(i, n) {
      d[x]++;
      x += co[s[i] - 'A'];
      res += d[x];
    }
    return res;
  };

  ll ans = n * ll(n + 1) / 2;
  ans -= f({1, -1, 0});
  ans -= f({1, 0, -1});
  ans -= f({0, 1, -1});
  const int B = 1e6;
  ans += f({B + 1, -B, -1}) * 2;
  cout << ans << endl;
  return 0;
}