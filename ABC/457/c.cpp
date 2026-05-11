#include <atcoder/all>
#include <bits/stdc++.h>
#include <iostream>

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
  ll n, k;
  cin >> n >> k;
  vector<ll> l(n);
  vector<vector<ll>> a(n);
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    a[i] = vector<ll>(l[i]);
    for (int j = 0; j < l[i]; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  ll idx = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum < k && k <= sum + (ll)l[i] * c[i]) {
      idx = i;
      break;
    }
    sum += (ll)l[i] * c[i];
  }
  ll rest = k - sum - 1;
  ll pos = rest % l[idx];
  cout << a[idx][pos] << endl;

  return 0;
}
