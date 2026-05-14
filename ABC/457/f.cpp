#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using mint = modint998244353;

mint op(mint a, mint b) { return a + b; }
mint e() { return 0; }
mint mapping(mint f, mint x) { return x * f; }
mint composition(mint f, mint g) { return f * g; }
mint id() { return 1; }

int main() {
  int n;
  cin >> n;
  vector<int> d(n - 1);
  rep(i, n - 1) cin >> d[i];
  lazy_segtree<mint, op, e, mint, mapping, composition, id> seg(n);

  if (d[n - 2] != 1) {
    cout << 0 << endl;
    return 0;
  }

  seg.set(n - 1, 1);
  seg.set(n - 2, 1);
  for (int i = n - 3; i >= 0; i--) {
    mint x = seg.get(i + d[i]);
    if (d[i] != d[i + 1]) {
      seg.apply(0, n, 0);
    } else {
      seg.apply(0, n, n - i - 2);
    }
    seg.set(i, x);
    seg.set(i + d[i], seg.get(i + d[i]) + x);
  }

  mint ans = seg.all_prod();
  cout << ans.val() << endl;
  return 0;
}