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
  string s;
  cin >> s;
  int n = s.size();

  ll cnt = 0;
  rep(i, n) {
    if (s[i] == 'C') {
      cnt += min(i, n - 1 - i) + 1;
    }
  }

  cout << cnt << endl;

  return 0;
}
