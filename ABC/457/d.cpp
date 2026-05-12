#include <atcoder/all>
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 == (int)v.size() ? "" : ", ");
  }
  os << "]";
  return os;
}

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }

  auto f = [&](ll m) {
    ll tot = 0;
    rep(i, n) {
      ll cnt = max(0LL, (m - a[i] + i) / (i + 1));
      tot += cnt;
      if (tot > k) {
        return false;
      }
    }
    return tot <= k;
  };

  ll l = 0;
  ll r = INT64_MAX;
  while (l + 1 != r) {
    ll m = (l + r) / 2;
    if (!f(m)) {
      r = m;
    } else {
      l = m;
    }
  }

  cout << l << endl;

  return 0;
}
