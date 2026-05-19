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
  int x, q;
  cin >> x >> q;

  priority_queue<int> R;
  priority_queue<int, vector<int>, greater<int>> L;

  L.push(x);
  rep(i, q) {
    int a, b;
    cin >> a >> b;
    if (L.top() <= a) {
      L.push(a);
    } else {
      R.push(a);
    }

    if (L.top() <= b) {
      L.push(b);
    } else {
      R.push(b);
    }

    if (L.size() < R.size()) {
      int c = R.top();
      R.pop();
      L.push(c);
    } else if (L.size() > R.size() + 1) {
      int c = L.top();
      L.pop();
      R.push(c);
    }

    cout << L.top() << endl;
  }

  return 0;
}
