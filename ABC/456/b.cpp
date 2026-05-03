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
  vector<vector<int>> d(3, vector<int>(6));
  rep(i, 3) {
    rep(j, 6) { cin >> d[i][j]; }
  }

  int cnt = 0;
  for (auto e1 : d[0]) {
    for (auto e2 : d[1]) {
      for (auto e3 : d[2]) {
        vector<int> v = {e1, e2, e3};
        sort(v.begin(), v.end());
        if (v[0] == 4 && v[1] == 5 && v[2] == 6) {
          cnt++;
        }
      }
    }
  }

  double ans = (double)cnt / 216.0;
  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
