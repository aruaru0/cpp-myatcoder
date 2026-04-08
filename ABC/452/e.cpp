#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  // 実装上は、 B についても長さを 1 増やし、1-indexedとして扱えるようにします。
  vector<mint> A(N + 1), B(M + 1);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    A[i] = x;
  }
  for (int j = 1; j <= M; j++) {
    int x;
    cin >> x;
    B[j] = x;
  }

  vector<mint> C(N + 1);
  for (int i = 0; i <= N; i++)
    C[i] = A[i] * i;

  // A と C の累積和
  vector<mint> acc_A(N + 2), acc_C(N + 2);
  for (int i = 0; i <= N; i++) {
    acc_A[i + 1] = acc_A[i] + A[i];
    acc_C[i + 1] = acc_C[i] + C[i];
  }

  auto f = [&](int l, int r) -> mint {
    r = min(r, N + 1); // N+1 とのminをとると、 i > N となる A_i
                       // を陽に持たなくても良いです。

    return (acc_C[r] - acc_C[l]) - l * (acc_A[r] - acc_A[l]);
  };

  mint ans = 0;
  for (int j = 1; j <= M; j++) {
    mint x = 0;
    for (int k = 0; k < (N + 1 + j - 1) / j; k++) {
      x += f(j * k, j * k + j);
    }
    ans += x * B[j];
  }
  cout << ans.val() << endl;
}
