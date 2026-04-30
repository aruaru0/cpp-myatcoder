#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using mint = modint998244353;

struct S {
  mint s0, s1, s2;
};
S op(S a, S b) { return S(a.s0 + b.s0, a.s1 + b.s1, a.s2 + b.s2); }
S e() { return S(0, 0, 0); }

S mapping(mint f, S x) {
  x.s2 += x.s1 * f * 2 + x.s0 * f * f;
  x.s1 += x.s0 * f;
  return x;
}
mint composition(mint f, mint g) { return f + g; }
mint id() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  lazy_segtree<S, op, e, mint, mapping, composition, id> t(
      vector<S>(n, S(1, 0, 0)));

  rep(qi, q) {
    int l, r, a;
    cin >> l >> r >> a;
    --l;
    t.apply(l, r, a);
    S s = t.prod(l, r);
    mint ans = (s.s1 * s.s1 - s.s2) / 2;
    cout << ans.val() << endl;
  }
  return 0;
}