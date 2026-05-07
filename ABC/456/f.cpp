#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>

const long long INF = 1e18;
using M = array<long long, 4>;
M mul(M l, M r) {
  M x{0, 0, 0, 0};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      x[2 * i + j] =
          min(l[2 * i + 0] + r[2 * 0 + j], l[2 * i + 1] + r[2 * 1 + j]);
  return x;
}

M op(M l, M r) { return mul(r, l); }
M e() { return M{0, INF, INF, 0}; }

void solve() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (auto &v : A)
    cin >> v;
  vector<M> data(N);
  for (int i = 0; i < N; i++)
    data[i] = M{INF, 0, A[i], A[i]};
  atcoder::segtree<M, op, e> seg(data);
  long long ans = INF;
  for (int l = 0; l + K <= N; l++) {
    auto p = seg.prod(l, l + K);
    ans = min(ans, p[2]);
    if (l > 0)
      ans = min(ans, A[l - 1] + p[3]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--)
    solve();
}