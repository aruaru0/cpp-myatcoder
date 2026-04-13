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
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];

  auto sign = [](ll x) -> bool {
    if (x >= 0)
      return true;
    return false;
  };

  auto f = [&](int b) -> int {
    ll pos = 1;
    int cnt = 0;
    rep(i, n) {
      ll nxt = pos;
      //   cout << pos << "->" << nxt << endl;
      if ((b >> i) % 2) {
        nxt += 2 * l[i];
      } else {
        nxt -= 2 * l[i];
      }
      if (sign(pos) != sign(nxt)) {
        cnt++;
      }
      pos = nxt;
    }
    return cnt;
  };

  int ans = 0;
  rep(b, 1 << n) { ans = max(ans, f(b)); }

  cout << ans << endl;

  return 0;
}
