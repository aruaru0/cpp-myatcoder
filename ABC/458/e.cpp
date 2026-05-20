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

mint h(int k, int n) { return comb(n + k - 1, k); }

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  mint ans;
  rep(ac, 2) {
    for (int g = 2;; g++) {
      int gc = g / 2, ga = g - gc;
      if (a < ga || c < gc)
        break;
      if (b < g - 1)
        break;
      mint now = h(a - ga, ga);
      now *= h(c - gc, gc);
      now *= h(b - (g - 1), a + c + 1);
      ans += now;
    }
    swap(a, c);
  }
  cout << ans.val() << endl;
  return 0;
}