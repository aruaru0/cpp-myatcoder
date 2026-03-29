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
  int q;
  cin >> q;

  priority_queue<int, vector<int>, greater<int>> pq;

  rep(qi, q) {
    int t, h;
    cin >> t >> h;
    if (t == 1) {
      pq.push(h);
    } else {
      while (!pq.empty() && pq.top() <= h) {
        pq.pop();
      }
    }
    cout << pq.size() << endl;
  }

  return 0;
}
