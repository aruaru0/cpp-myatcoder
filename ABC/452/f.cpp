#include "atcoder/fenwicktree.hpp"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
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
  vector<int> p(n);
  rep(i, n) cin >> p[i], p[i]--;

  auto f = [&](ll k) -> ll {
    ll res = 0, now = 0;
    fenwick_tree<int> d(n);
    int l = 0;
    rep(r, n) {
      now += d.sum(p[r], n);
      d.add(p[r], 1);
      while (now > k && l <= r) {
        d.add(p[l], -1);
        now -= d.sum(0, p[l]);
        l++;
      }
      res += r - l + 1;
    }
    return res;
  };

  cout << f(k) - f(k - 1) << endl;

  return 0;
}