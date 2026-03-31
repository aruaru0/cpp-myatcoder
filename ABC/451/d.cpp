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

  vector<ll> a;
  vector<int> l;
  int cur = 1;
  while (cur <= 1e9) {
    a.push_back(cur);
    l.push_back(to_string(cur).size());
    cur *= 2;
  }

  vector<ll> pow(12);
  pow[0] = 1;
  for (int i = 1; i < 12; i++) {
    pow[i] = pow[i - 1] * 10;
  }

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int e : a) {
    pq.push(e);
  }

  int cnt = 0;
  int last = 0;
  while (true) {
    int x = pq.top();
    pq.pop();

    if (x == last) {
      continue;
    }
    last = x;
    cnt++;
    if (cnt == n) {
      cout << x << endl;
      return 0;
    }

    string s = to_string(x);
    for (int i = 0; i < a.size(); i++) {
      ll t = a[i];
      ll m = s.size();
      if (m + l[i] > 10) {
        continue;
      }
      ll v = t * pow[m] + x;
      if (v <= 1e9) {
        pq.push(v);
      }
    }
  }

  return 0;
}
