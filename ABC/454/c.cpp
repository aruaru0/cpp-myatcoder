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
  vector<vector<int>> node(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    node[a].push_back(b);
  }

  vector<bool> visited(n, false);

  function<void(int)> dfs = [&](int cur) {
    visited[cur] = true;
    for (int e : node[cur]) {
      if (visited[e])
        continue;
      dfs(e);
    }
  };

  dfs(0);

  int cnt = 0;
  rep(i, n) {
    if (visited[i])
      cnt++;
  }
  cout << cnt << endl;

  return 0;
}
