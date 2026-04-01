#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;

  const int M = 1e4;
  using P = pair<int, int>;
  vector<vector<P>> es(M);
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      int a;
      cin >> a;
      es[a].emplace_back(i, j);
    }
  }

  vector<vector<P>> g(n);
  dsu uf(n);
  rep(c, M) {
    for (auto [a, b] : es[c]) {
      if (uf.same(a, b))
        continue;
      uf.merge(a, b);
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
  }

  const int INF = 1001001001;
  vector dist(n, vector<int>(n, INF));
  rep(sv, n) {
    queue<int> q;
    q.push(sv);
    vector<int> &d = dist[sv];
    d[sv] = 0;
    while (q.size()) {
      int v = q.front();
      q.pop();
      for (auto [to, cost] : g[v]) {
        if (d[to] != INF)
          continue;
        d[to] = d[v] + cost;
        q.push(to);
      }
    }
  }

  rep(c, M) {
    for (auto [a, b] : es[c]) {
      if (dist[a][b] != c) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}