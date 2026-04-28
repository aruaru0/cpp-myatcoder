#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coutにvector<int>を表示させる
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  }
  return os;
}

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> up(n, -1), down(n, -1);

  rep(qi, q) {
    int c, p;
    cin >> c >> p;
    c--;
    p--;
    if (down[c] != -1) {
      up[down[c]] = -1;
    }
    up[p] = c;
    down[c] = p;
  }

  vector<int> ans(n);
  rep(i, n) {
    if (down[i] == -1) { // 一番下の場合
      // 上にたどる
      int cur = i;
      while (cur != -1) {
        cur = up[cur];
        ans[i]++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
