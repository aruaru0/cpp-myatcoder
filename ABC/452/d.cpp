#include <atcoder/all>
#include <bits/stdc++.h>

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
  using namespace std;
  string S, T;
  cin >> S >> T;

  int tlen = T.size();

  vector<ll> dp(tlen + 1);

  ll ans = 0;
  for (const auto s : S) {
    ++dp[0];
    for (int i = tlen - 1; i >= 0; i--) {
      if (s == T[i]) {
        dp[i + 1] += dp[i];
        dp[i] = 0;
      }
    }
    ll sum = 0;
    rep(i, tlen) sum += dp[i];
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}
