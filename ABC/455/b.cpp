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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  auto f = [&](int h1, int h2, int w1, int w2) -> bool {
    for (int i = h1; i <= h2; i++) {
      for (int j = w1; j <= w2; j++) {
        if (s[i][j] != s[h1 + h2 - i][w1 + w2 - j]) {
          return false;
        }
      }
    }
    return true;
  };

  int cnt = 0;
  rep(h1, h) {
    for (int h2 = h1; h2 < h; h2++) {
      rep(w1, w) {
        for (int w2 = w1; w2 < w; w2++) {
          if (f(h1, h2, w1, w2)) {
            cnt++;
          }
        }
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
