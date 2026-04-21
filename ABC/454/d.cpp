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

int solve() {
  string a, b;
  cin >> a >> b;

  auto f = [&](string s) -> string {
    deque<char> ret;
    for (char c : s) {
      int l = ret.size();
      if (l >= 3 && ret[l - 3] == '(' && ret[l - 2] == 'x' &&
          ret[l - 1] == 'x' && c == ')') {
        ret.pop_back();
        ret.pop_back();
        ret.pop_back();
        ret.push_back('x');
        ret.push_back('x');
      } else {
        ret.push_back(c);
      }
    }
    return string(ret.begin(), ret.end());
  };

  string fa = f(a);
  string fb = f(b);

  if (fa == fb) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) { solve(); }
  return 0;
}
