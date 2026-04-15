#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
  int n;
  vector<mint> d;
  modinv() : n(2), d({0, 1}) {}
  mint operator()(int i) {
    while (n <= i)
      d.push_back(-d[mint::mod() % n] * (mint::mod() / n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
  int n;
  vector<mint> d;
  modfact() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i)
      d.push_back(d.back() * n), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} facts;
struct modfactinv {
  int n;
  vector<mint> d;
  modfactinv() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i)
      d.push_back(d.back() * invs(n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} ifacts;
mint comb(int n, int k) {
  if (n < k || k < 0)
    return 0;
  return facts(n) * ifacts(k) * ifacts(n - k);
}

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
  int n;
  cin >> n;

  vector<int> d(n + 2), d2(n + 2);
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    d[l]++;
    d[r + 1]--;
    l = max(l, n - r);
    r = min(r, n - l);
    if (l <= r)
      d2[l]++, d2[r + 1]--;
  }

  rep(i, n + 1) d[i + 1] += d[i];
  rep(i, n + 1) d2[i + 1] += d2[i];

  mint ans;
  for (int x = 1; x < n; x++) {
    int y = n - x;
    int a = d[x], b = d[y], c = d2[x];
    a -= c;
    b -= c;
    if (a + b + c != n)
      continue;
    if (a > x || b > y)
      continue;
    ans += comb(c, x - a);
  }
  cout << ans.val() << endl;
  return 0;
}