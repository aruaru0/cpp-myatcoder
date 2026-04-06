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
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int m;
  cin >> m;
  vector<string> s(m);
  rep(i, m) cin >> s[i];

  map<tuple<int, int, char>, bool> c;
  rep(i, m) {
    rep(j, s[i].size()) { c[{s[i].size(), j + 1, s[i][j]}] = true; }
  }

  rep(i, m) {
    if (s[i].size() != n) {
      cout << "No" << endl;
      continue;
    }
    bool ok = true;
    rep(j, n) {
      if (!c[{a[j], b[j], s[i][j]}]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
