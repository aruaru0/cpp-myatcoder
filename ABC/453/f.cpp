#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> to(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> c(k);
  rep(i, k) cin >> c[i];

  int m = 0;
  vector<bool> leaf(n);
  rep(i, n) {
    leaf[i] = to[i].size() == 1;
    if (leaf[i])
      m++;
  }

  int x = 0;
  {
    auto f = [&](auto f, int v, int p = -1) -> int {
      int res = leaf[v], mx = 0;
      for (int u : to[v])
        if (u != p) {
          int r = f(f, u, v);
          res += r;
          mx = max(mx, r);
        }
      mx = max(mx, m - res);
      if (mx * 2 <= m)
        x = v;
      return res;
    };
    f(f, 0);
  }

  vector<bool> used(n);
  vector<vector<int>> gs;
  for (int v : to[x]) {
    gs.push_back({});
    auto f = [&](auto f, int v, int p = -1) -> void {
      if (leaf[v])
        gs.back().push_back(v), used[v] = true;
      for (int u : to[v])
        if (u != p) {
          f(f, u, v);
        }
    };
    f(f, v, x);
  }
  sort(gs.begin(), gs.end(),
       [&](auto &a, auto &b) { return a.size() > b.size(); });

  vector<int> p;
  for (auto &g : gs)
    for (int v : g)
      p.push_back(v);
  {
    vector<int> o = p;
    vector<int> is;
    rep(i, 2) rep(j, o.size()) if (j % 2 == i) is.push_back(j);
    rep(i, o.size()) p[is[i]] = o[i];
  }
  p.push_back(x);
  used[x] = true;
  rep(i, n) if (!used[i]) p.push_back(i);

  vector<int> ci(k);
  rep(i, k) ci[i] = i;
  sort(ci.begin(), ci.end(), [&](int i, int j) { return c[i] > c[j]; });
  int pi = 0;
  vector<int> ans(n);
  for (int i : ci) {
    if (c[i] == 1 && pi < m) {
      cout << "-1\n";
      return;
    }
    rep(j, c[i]) {
      if (pi == n)
        break;
      ans[p[pi++]] = i + 1;
    }
  }

  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  rep(ti, T) solve();
  return 0;
}