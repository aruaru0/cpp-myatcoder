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
  int n, m;
  cin >> n >> m;

  vector<int> cur(m, 0);
  vector<int> nxt(m, 0);

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    cur[a - 1]++;
    nxt[b - 1]++;
  }

  rep(i, m) { cout << nxt[i] - cur[i] << endl; }

  return 0;
}
