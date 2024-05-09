#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
int pc(int x) { return __builtin_popcount(x);}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<P>> g(n);
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b,-c);
    g[b].emplace_back(a,c);
  }

  vector<bool> used(n);
  vector<int> idx(n);
  vector<vector<int>> vs;
  vector<int> xs;
  rep(i,n) if (!used[i]) {
    auto dfs = [&](auto dfs, int v) -> void {
      vs.back().push_back(v);
      used[v] = true;
      for (auto [u,c] : g[v]) {
        if (used[u]) continue;
        idx[u] = idx[v]+c;
        dfs(dfs,u);
      }
    };
    vs.push_back(vector<int>());
    dfs(dfs,i);
    int mn = 0;
    for (int v : vs.back()) mn = min(mn,idx[v]);
    for (int v : vs.back()) idx[v] -= mn;
    int x = 0;
    for (int v : vs.back()) x |= 1<<idx[v];
    xs.push_back(x);
  }

  int n2 = 1<<n;
  m = xs.size();
  vector<int> ans(n,-1);
  rep(k,m) {
    vector<bool> dp(n2);
    dp[0] = true;
    int num = 0;
    rep(i,m) if (i != k) {
      rep(s,n2) if (pc(s) == num && dp[s]) {
        int x = xs[i];
        while (x < n2) {
          if ((s&x) == 0) dp[s|x] = true;
          x <<= 1;
        }
      }
      num += vs[i].size();
    }

    int x = xs[k], cnt = 0;
    int offset = 0, i = 0;
    while (x < n2) {
      if (dp[(n2-1)^x]) offset = i, cnt++;
      x <<= 1; i++;
    }
    if (cnt == 1) {
      for (int v : vs[k]) ans[v] = offset+idx[v]+1;
    }
  }

  rep(i,n) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
