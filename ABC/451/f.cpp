#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n, q;
  cin >> n >> q;

  dsu uf(n * 2);
  vector<int> black(n * 2);
  rep(i, n) black[i] = 1;

  auto merge = [&](int a, int b) {
    int x = black[uf.leader(a)] + black[uf.leader(b)];
    uf.merge(a, b);
    black[uf.leader(a)] = x;
  };
  auto get = [&](int v) {
    return min(black[uf.leader(v)], black[uf.leader(v + n)]);
  };

  bool ok = true;
  int ans = 0;
  rep(qi, q) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (!uf.same(a, b + n)) {
      ans -= get(a) + get(b);
      merge(a, b + n);
      merge(a + n, b);
      ans += get(a);
      if (uf.same(a, a + n))
        ok = false;
    }
    if (!ok)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}