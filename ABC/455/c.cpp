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
  int n, k;
  cin >> n >> k;

  map<int, int> m;
  rep(i, n) {
    int a;
    cin >> a;
    m[a]++;
  }

  vector<ll> b;
  for (auto [key, val] : m) {
    b.push_back(key * val);
  }

  sort(b.begin(), b.end());

  ll tot = 0;
  for (int i = 0; i < (int)b.size() - k; i++)
    tot += b[i];

  cout << tot << endl;

  return 0;
}
