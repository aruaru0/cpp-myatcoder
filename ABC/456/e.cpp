#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edges.push_back({u, v});
  }

  int w;
  cin >> w;
  vector<string> s(n);
  scc_graph g(n * w);

  rep(i, n) {
    cin >> s[i];
    rep(j, w) {
      int nj = (j + 1) % w;
      if (s[i][j] == 'o' && s[i][nj] == 'o') {
        g.add_edge(i * w + j, i * w + nj);
      }
    }
  }

  rep(i, w) {
    int j = (i + 1) % w;
    // cout << i << ", " << j << endl;

    // 他のノードへの遷移
    for (auto [u, v] : edges) {
      //   cout << "edge: " << u << ", " << v << endl;
      if (s[u][i] == 'o' && s[v][j] == 'o') {
        g.add_edge(u * w + i, v * w + j);
      }
      if (s[v][i] == 'o' && s[u][j] == 'o') {
        g.add_edge(v * w + i, u * w + j);
      }
    }
  }

  bool ok = false;
  auto ret = g.scc();
  for (auto e : ret) {
    if (e.size() >= w) {
      ok = true;
    }
    // cout << e << " ";
  }
  //   cout << endl;
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  int t;
  cin >> t;

  rep(i, t) { solve(); }

  return 0;
}
